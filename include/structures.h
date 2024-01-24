/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:02:27 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 14:26:17 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_vec3		t_vec3;
typedef struct s_vec3		t_point3;
typedef struct s_vec3		t_color3;
typedef struct s_scene		t_scene;
typedef struct s_camera		t_camera;
typedef struct s_canvas		t_canvas;
typedef struct s_ray		t_ray;
typedef struct s_hit_record	t_hit_record;
typedef struct s_object		t_object;
typedef struct s_light		t_light;
typedef struct s_light_arg	t_light_arg;
typedef struct s_sphere		t_sphere;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_formula	t_formula;
typedef struct s_mlx_vars	t_mlx_vars;
typedef struct s_mlx_data	t_mlx_data;
typedef struct s_checklist	t_checklist;

typedef int					t_bool;
# define TRUE 1
# define FALSE 0

typedef int					t_object_type;
# define LIGHT 0
# define SP 1
# define PL 2
# define CY 3

# define CANVAS_WIDTH 1200
# define CANVAS_HEIGHT 900
# define VIEWPORT_HEIGHT 2.0
# define EPSILON 1e-6
# define PIE 3.14159265
# define LUMEN 2
# define SS 0.5
# define SN 64
# define TOP 1
# define BOTTOM -1
# define STDERR 2

struct	s_vec3
{
	double	x;
	double	y;
	double	z;
};

struct s_camera
{
	t_point3	org;
	t_vec3		normal;
	t_vec3		w_axis;
	t_vec3		h_axis;
	double		viewport_w;
	double		viewport_h;
	t_vec3		horizontal;
	t_vec3		vertical;
	double		focal_length;
	t_point3	left_bottom;
};

struct s_canvas
{
	int		width;
	int		height;
	double	aspect_ratio;
};

struct s_ray
{
	t_point3	org;
	t_vec3		dirc;
};

struct s_hit_record
{
	t_point3	p;
	t_vec3		normal;
	double		tmin;
	double		tmax;
	double		t;
	t_bool		front_face;
	t_color3	albedo;
};

struct s_object
{
	t_object_type	type;
	void			*element;
	t_color3		albedo;
	void			*next;
};

struct s_light
{
	t_point3	org;
	t_color3	color;
	double		bright_ratio;
};

struct s_light_arg
{
	t_vec3	dir;
	double	length;
	t_ray	ray;
};

struct s_sphere
{
	t_point3	center;
	double		radius;
	double		radius2;
};

struct s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
};

struct s_plane
{
	t_point3	point;
	t_vec3		normal;
};

struct s_cylinder
{
	t_point3	center;
	t_point3	bottom;
	t_vec3		dirc;
	double		radius;
	double		height;
	t_vec3		hc;
	t_point3	h;
	t_point3	w;
};

struct s_formula
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	sqrtd;
	double	root;
};

struct s_mlx_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
};

struct s_mlx_vars
{
	void			*mlx_ptr;
	void			*mlx_window;
	t_mlx_data		painting;
};

struct s_checklist
{
	int	camera;
	int	ambient;
	int	light;
};

#endif
