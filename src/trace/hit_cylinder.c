/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:47:01 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/10 14:58:58 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

static t_bool	check_cy_height(t_cylinder *cy, t_point3 hit_point,
		double *hit_height)
{
	*hit_height = vdot(vvminus(hit_point, cy->center), cy->dirc);
	if (fabs(*hit_height) <= cy->height)
		return (TRUE);
	return (FALSE);
}

static t_bool	hit_cy_slide(t_cylinder *cy, t_ray *ray, t_hit_record *rec)
{
	t_formula	f;
	double		hit_height;

	cy->w = vvminus(ray->org, cy->bottom);
	f.a = vec_pow(ray->dirc) - pow(vdot(ray->dirc, cy->h), 2);
	f.b = (vdot(ray->dirc, cy->w) - (vdot(ray->dirc, cy->h)
				* vdot(cy->w, cy->h))) * 2;
	f.c = vec_pow(cy->w) - pow(vdot(cy->w, cy->h), 2) - pow(cy->radius, 2);
	f.discriminant = pow(f.b, 2) - 4 * f.a * f.c;
	if (f.discriminant < 0)
		return (FALSE);
	else if (f.discriminant == 0)
		f.root = -(f.b) / (2 * f.a);
	else if (f.discriminant > 0 && !check_root(&f, rec))
		return (FALSE);
	if (!check_cy_height(cy, ray_at(ray, f.root), &hit_height))
		return (FALSE);
	rec->t = f.root;
	rec->p = ray_at(ray, f.root);
	rec->normal = vunit(vvminus(rec->p, vvplus(cy->center,
					vdmult(cy->dirc, hit_height))));
	rec->tmax = rec->t;
	set_face_normal(ray, rec);
	return (TRUE);
}

static t_bool	hit_cy_cap(t_cylinder *cy, t_ray *ray, t_hit_record *rec,
		double cap)
{
	t_vec3		dirc;
	t_vec3		normal;
	t_point3	center;
	t_formula	f;
	double		diameter;

	dirc = vdmult(cy->dirc, cy->height * cap);
	normal = vunit(dirc);
	center = vvplus(cy->center, dirc);
	f.a = vdot(normal, ray->dirc);
	f.b = vdot(vvminus(ray->org, center), normal);
	if (f.a == 0)
		return (FALSE);
	f.root = -f.b / f.a;
	diameter = vec_length(vvminus(center, ray_at(ray, f.root)));
	if (diameter > cy->radius || f.root < rec->tmin || rec->tmax < f.root)
		return (FALSE);
	rec->t = f.root;
	rec->p = ray_at(ray, f.root);
	rec->tmax = rec->t;
	rec->normal = normal;
	set_face_normal(ray, rec);
	return (TRUE);
}

t_bool	hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_bool		res;

	cy = world->element;
	res = FALSE;
	res += hit_cy_slide(cy, ray, rec);
	res += hit_cy_cap(cy, ray, rec, TOP);
	res += hit_cy_cap(cy, ray, rec, BOTTOM);
	rec->albedo = world->albedo;
	return (res);
}
