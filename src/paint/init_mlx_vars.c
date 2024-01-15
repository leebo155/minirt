/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:19:15 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/15 13:42:27 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paint.h"

static int	ft_hook_esc_press(int keycode, t_mlx_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx_ptr, vars->mlx_window);
		mlx_destroy_image(vars->mlx_ptr, vars->painting.img);
		exit(0);
	}
	return (0);
}

static int	ft_hook_close_window(int keycode, t_mlx_vars *vars)
{
	(void)keycode;
	(void)vars;
	exit(0);
	return (0);
}

void	regist_hooks(t_mlx_vars *vars)
{
	mlx_hook(vars->mlx_window, 2, 1L, ft_hook_esc_press, vars);
	mlx_hook(vars->mlx_window, 17, 0L, ft_hook_close_window, vars);
}

t_bool	init_mlx_vars(t_mlx_vars *vars)
{
	vars->mlx_ptr = mlx_init();
	if (vars->mlx_ptr == NULL)
		return (FALSE);
	vars->mlx_window = mlx_new_window(vars->mlx_ptr,
			CANVAS_WIDTH, CANVAS_HEIGHT, "miniRT");
	if (vars->mlx_window == NULL)
		return (FALSE);
	vars->painting.img = mlx_new_image(vars->mlx_ptr,
			CANVAS_WIDTH, CANVAS_HEIGHT);
	if (vars->painting.img == NULL)
		return (FALSE);
	vars->painting.addr = mlx_get_data_addr(vars->painting.img,
			&(vars->painting.bpp), &(vars->painting.line_length),
			&(vars->painting.endian));
	if (vars->painting.addr == NULL)
		return (FALSE);
	return (TRUE);
}
