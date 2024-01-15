/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:39:22 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/15 13:49:27 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "paint.h"

static int	get_rgb_int(t_color3 color)
{
	int	ret;

	ret = (int)(255.999 * color.x);
	ret = ret << 8;
	ret += (int)(255.999 * color.y);
	ret = ret << 8;
	ret += (int)(255.999 * color.z);
	return (ret);
}

static void	put_pixel(t_mlx_data *painting, int x, int y, t_color3 color)
{
	char	*pixel;

	pixel = painting->addr
		+ (y * painting->line_length
			+ x * (painting->bpp / 8));
	(*(unsigned int *)pixel) = get_rgb_int(color);
}

void	draw_painting(t_mlx_data *painting, t_scene **scene)
{
	int	x;
	int	y;

	y = 0;
	while (y < CANVAS_HEIGHT)
	{
		x = 0;
		while (x < CANVAS_WIDTH)
		{
			(*scene)->ray = ray_primary(&(*scene)->camera,
					(double)x / (CANVAS_WIDTH -1),
					(double)y / (CANVAS_HEIGHT - 1));
			put_pixel(painting, x, CANVAS_HEIGHT - y - 1,
				ray_color(*scene));
			x++;
		}
		y++;
	}
}
