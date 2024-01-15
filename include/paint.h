/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 11:23:02 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/15 13:40:33 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAINT_H
# define PAINT_H

# include "structures.h"
# include "trace.h"
# include "mlx.h"

void	regist_hooks(t_mlx_vars *vars);
t_bool	init_mlx_vars(t_mlx_vars *vars);
void	draw_painting(t_mlx_data *painting, t_scene **scene);

#endif
