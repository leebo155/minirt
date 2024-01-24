/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 14:10:49 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 14:54:11 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "valid.h"
#include "paint.h"

int	main(int argc, char *argv[])
{
	t_scene		*scene;
	t_mlx_vars	vars;

	if (argc == 1)
	{
		print_error("execute without arguments.");
		return (-1);
	}
	if (!check_valid(argv[1]))
		return (-1);
	if (!create_scene(&scene, argv[1]))
		return (-1);
	if (!init_mlx_vars(&vars))
	{
		destroy_scene(&scene);
		return (-1);
	}
	draw_painting(&vars.painting, &scene);
	destroy_scene(&scene);
	regist_hooks(&vars);
	mlx_put_image_to_window(vars.mlx_ptr, vars.mlx_window,
		vars.painting.img, 0, 0);
	mlx_loop(vars.mlx_ptr);
	return (0);
}
