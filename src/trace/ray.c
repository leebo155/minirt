/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:55:44 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/10 15:15:38 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_ray	ray(t_point3 org, t_vec3 dirc)
{
	t_ray	ray;

	ray.org = org;
	ray.dirc = vunit(dirc);
	return (ray);
}

t_point3	ray_at(t_ray *ray, double t)
{
	t_point3	at;

	at = vvplus(ray->org, vdmult(ray->dirc, t));
	return (at);
}

t_ray	ray_primary(t_camera *cam, double u, double v)
{
	t_ray	ray;

	ray.org = cam->org;
	ray.dirc = vunit(vvminus(vvplus(vvplus(cam->left_bottom,
						vdmult(cam->horizontal, u)),
					vdmult(cam->vertical, v)),
				cam->org));
	return (ray);
}

t_color3	ray_color(t_scene *scene)
{
	scene->rec.tmin = EPSILON;
	scene->rec.tmax = INFINITY;
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_lighting(scene));
	else
		return (color3(0, 0, 0));
}
