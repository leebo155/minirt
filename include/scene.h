/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:13:52 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/13 14:13:23 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "structures.h"
# include "vector.h"

t_color3	ambient(double ratio, t_color3 color);
t_canvas	canvas(int width, int height);
t_camera	camera(t_canvas *canvas, t_point3 org, t_vec3 dirc, double range);
t_object	*object(t_object_type type, void *element, t_color3 albedo);
void		obj_add(t_object **list, t_object *new);
t_object	*obj_last(t_object *list);
t_light		*light(t_point3 org, double ratio, t_color3 color);
t_sphere	*sphere(t_point3 center, double radius);
t_plane		*plane(t_point3 point, t_vec3 normal);
t_cylinder	*cylinder(t_point3 center, t_vec3 dirc, double dia, double height);
t_bool		create_scene(t_scene **scene, char *file);
void		destroy_scene(t_scene **scene);
t_bool		input_camera(char *line, t_scene **scene);
t_bool		input_light(char *line, t_scene **scene);
t_bool		input_sphere(char *line, t_scene **scene);
t_bool		input_plane(char *line, t_scene **scene);
t_bool		input_cylinder(char *line, t_scene **scene);
double		ddouble(char **line);
t_vec3		vvector(char **line);

#endif
