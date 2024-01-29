/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 16:09:49 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/29 14:44:19 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trace.h"

t_color3	phong_lighting(t_scene *scene)
{
	t_color3	light_color;
	t_object	*lights;

	light_color = color3(0, 0, 0);
	lights = scene->light;
	while (lights)
	{
		if (lights->type == LIGHT)
			light_color = vvplus(light_color,
					point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = vvplus(light_color, scene->ambient);
	return (vmin(vvmult(light_color, scene->rec.albedo), color3(1, 1, 1)));
}

t_vec3	reflect(t_vec3 v, t_vec3 n)
{
	return (vvminus(v, vdmult(n, vdot(v, n) * 2)));
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_light_arg	l;
	t_color3	diffuse;
	t_color3	specular;
	t_vec3		view_dir;
	t_vec3		reflect_dir;

	l.dir = vvminus(light->org, scene->rec.p);
	l.length = vec_length(l.dir);
	l.ray = ray(vvplus(scene->rec.p,
				vdmult(scene->rec.normal, EPSILON)), l.dir);
	if (in_shadow(scene->world, l.ray, l.length))
		return (color3(0, 0, 0));
	diffuse = vdmult(light->color,
			fmax(vdot(scene->rec.normal, l.ray.dirc), 0.0));
	view_dir = vunit(vdmult(scene->ray.dirc, -1));
	reflect_dir = reflect(vdmult(l.ray.dirc, -1), scene->rec.normal);
	specular = vdmult(vdmult(light->color, SS),
			pow(fmax(vdot(view_dir, reflect_dir), 0.0), SN));
	return (vdmult(vvplus(diffuse, specular), light->bright_ratio * LUMEN));
}

t_bool	in_shadow(t_object *objs, t_ray light_ray, double light_length)
{
	t_hit_record	rec;

	rec.tmin = EPSILON;
	rec.tmax = light_length;
	if (hit(objs, &light_ray, &rec))
		return (TRUE);
	return (FALSE);
}
