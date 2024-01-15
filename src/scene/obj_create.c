/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 16:42:01 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/13 14:13:07 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_color3	ambient(double ratio, t_color3 color)
{
	t_color3	amb;

	amb = vdmult(color, ratio);
	return (amb);
}

t_canvas	canvas(int width, int height)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = (double)width / (double)height;
	return (canvas);
}

t_camera	camera(t_canvas *canvas, t_point3 org, t_vec3 dirc, double range)
{
	t_camera	cam;
	t_vec3		up;

	cam.normal = vunit(dirc);
	if (cam.normal.y != 0 && (cam.normal.x == 0 && cam.normal.z == 0))
		up = vec3(0, 0, 1);
	else
		up = vec3(0, 1, 0);
	cam.w_axis = vunit(vcross(up, cam.normal));
	cam.h_axis = vunit(vcross(cam.normal, cam.w_axis));
	cam.viewport_h = VIEWPORT_HEIGHT;
	cam.viewport_w = VIEWPORT_HEIGHT * canvas->aspect_ratio;
	cam.focal_length = tan(((180 - range) / 2) * PIE / 180)
		* (cam.viewport_w / 2) * -1 ;
	cam.org = org;
	cam.horizontal = vdmult(vdmult(cam.w_axis, -1), cam.viewport_w);
	cam.vertical = vdmult(cam.h_axis, cam.viewport_h);
	cam.left_bottom = vvminus(vvminus(vvminus(cam.org,
					vdiv(cam.horizontal, 2)),
				vdiv(cam.vertical, 2)),
			vdmult(cam.normal, cam.focal_length));
	return (cam);
}

t_object	*object(t_object_type type, void *element, t_color3 albedo)
{
	t_object	*new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->type = type;
	new->element = element;
	new->albedo = albedo;
	new->next = NULL;
	return (new);
}

t_light	*light(t_point3 org, double ratio, t_color3 color)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->org = org;
	light->color = color;
	light->bright_ratio = ratio;
	return (light);
}
