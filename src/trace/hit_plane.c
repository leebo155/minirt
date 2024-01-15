/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:44:47 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/10 15:11:37 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_bool	hit_plane(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	double	denominator;
	double	numerator;
	double	root;

	pl = world->element;
	denominator = vdot(pl->normal, ray->dirc);
	numerator = vdot(vvminus(ray->org, pl->point), pl->normal);
	if (denominator == 0)
		return (FALSE);
	root = -numerator / denominator;
	if (root < rec->tmin || rec->tmax < root)
		return (FALSE);
	rec->t = root;
	rec->p = ray_at(ray, root);
	rec->normal = pl->normal;
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (TRUE);
}
