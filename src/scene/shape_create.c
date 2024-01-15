/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shape_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:18:33 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/12 14:31:18 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sp;

	sp = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sp)
		return (NULL);
	sp->center = center;
	sp->radius = fabs(radius);
	sp->radius2 = pow(radius, 2);
	return (sp);
}

t_plane	*plane(t_point3 point, t_vec3 normal)
{
	t_plane	*pl;

	pl = (t_plane *)malloc(sizeof(t_plane));
	if (!pl)
		return (NULL);
	pl->point = point;
	pl->normal = vunit(normal);
	return (pl);
}

t_cylinder	*cylinder(t_point3 center, t_vec3 dirc, double dia, double height)
{
	t_cylinder	*cy;
	t_point3	top;

	cy = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cy)
		return (NULL);
	cy->center = center;
	cy->dirc = vunit(dirc);
	cy->radius = fabs(dia) / 2;
	cy->height = fabs(height) / 2;
	top = vvminus(cy->center, vdmult(cy->dirc, cy->height));
	cy->bottom = vvplus(cy->center, vdmult(cy->dirc, cy->height));
	cy->hc = vvminus(top, cy->bottom);
	cy->h = vunit(cy->hc);
	return (cy);
}
