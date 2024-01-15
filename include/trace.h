/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 13:49:20 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/10 17:07:13 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRACE_H
# define TRACE_H

# include "structures.h"
# include "vector.h"

t_ray		ray(t_point3 org, t_vec3 dirc);
t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *cam, double u, double v);
t_color3	ray_color(t_scene *scene);
t_bool		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
t_bool		hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
void		set_face_normal(t_ray *r, t_hit_record *rec);
t_color3	phong_lighting(t_scene *scene);
t_color3	point_light_get(t_scene *scene, t_light *light);
t_vec3		reflect(t_vec3 v, t_vec3 n);
t_bool		in_shadow(t_object *objs, t_ray light_ray, double light_length);
t_bool		check_root(t_formula *f, t_hit_record *rec);
t_bool		hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_plane(t_object *world, t_ray *ray, t_hit_record *rec);
t_bool		hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec);

#endif
