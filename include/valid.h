/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:57:51 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 14:44:18 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALID_H
# define VALID_H

# include "structures.h"
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

t_bool		check_valid(char *file);
t_bool		check_whitespace(char *line);
t_bool		check_empty_line(char *line);
t_bool		check_double(char **line, double min, double max);
t_bool		check_vector(char **line, double min, double max);
t_bool		check_ambient(char *line);
t_bool		check_camera(char *line);
t_bool		check_light(char *line);
t_bool		check_sphere(char *line);
t_bool		check_plane(char *line);
t_bool		check_cylinder(char *line);
t_bool		my_atod(char **line, double *ret);
void		print_error(char *str);
void		print_nbr_error(int nbr, char *str);

#endif
