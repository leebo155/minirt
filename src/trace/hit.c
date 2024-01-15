/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:57:33 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/10 14:56:44 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

void	set_face_normal(t_ray *r, t_hit_record *rec)
{
	rec->front_face = vdot(r->dirc, rec->normal) < 0;
	if (!rec->front_face)
		rec->normal = vdmult(rec->normal, -1.0);
}

t_bool	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool			hit_anything;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_anything = FALSE;
	while (world)
	{
		if (hit_obj(world, ray, &temp_rec))
		{
			hit_anything = TRUE;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		world = world->next;
	}
	return (hit_anything);
}

t_bool	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_bool	hit_result;

	hit_result = FALSE;
	if (world->type == SP)
		hit_result = hit_sphere(world, ray, rec);
	else if (world->type == PL)
		hit_result = hit_plane(world, ray, rec);
	else if (world->type == CY)
		hit_result = hit_cylinder(world, ray, rec);
	return (hit_result);
}

t_bool	check_root(t_formula *f, t_hit_record *rec)
{
	f->sqrtd = sqrt(f->discriminant);
	f->root = (-f->b - f->sqrtd) / (2 * f->a);
	if (f->root < rec->tmin || rec->tmax < f->root)
	{
		f->root = (-f->b + f->sqrtd) / (2 * f->a);
		if (f->root < rec->tmin || rec->tmax < f->root)
			return (FALSE);
	}
	return (TRUE);
}
