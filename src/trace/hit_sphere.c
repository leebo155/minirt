/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:43:40 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/10 15:11:49 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_bool	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_sphere	*sp;
	t_vec3		oc;
	t_formula	f;

	sp = world->element;
	oc = vvminus(ray->org, sp->center);
	f.a = vdot(ray->dirc, ray->dirc);
	f.b = 2.0 * vdot(oc, ray->dirc);
	f.c = vdot(oc, oc) - sp->radius2;
	f.discriminant = pow(f.b, 2) - 4 * f.a * f.c;
	if (f.discriminant < 0 || !check_root(&f, rec))
		return (FALSE);
	rec->t = f.root;
	rec->p = ray_at(ray, f.root);
	rec->normal = vdiv(vvminus(rec->p, sp->center), sp->radius);
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}
