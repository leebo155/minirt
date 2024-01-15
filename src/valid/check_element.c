/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:35:57 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/12 13:12:47 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid.h"

t_bool	check_ambient(char *line)
{
	line++;
	if (!check_double(&line, 0, 1))
		return (FALSE);
	if (!check_vector(&line, 0, 255))
		return (FALSE);
	while (check_whitespace(line))
		line++;
	if (*line != 0)
		return (FALSE);
	return (TRUE);
}

t_bool	check_camera(char *line)
{
	line++;
	if (!check_vector(&line, 0, 0))
		return (FALSE);
	if (!check_vector(&line, -1, 1))
		return (FALSE);
	if (!check_double(&line, 0, 180))
		return (FALSE);
	while (check_whitespace(line))
		line++;
	if (*line != 0)
		return (FALSE);
	return (TRUE);
}

t_bool	check_light(char *line)
{
	line++;
	if (!check_vector(&line, 0, 0))
		return (FALSE);
	if (!check_double(&line, 0, 1))
		return (FALSE);
	if (!check_vector(&line, 0, 255))
		return (FALSE);
	while (check_whitespace(line))
		line++;
	if (*line != 0)
		return (FALSE);
	return (TRUE);
}

t_bool	check_sphere(char *line)
{
	line++;
	line++;
	if (!check_vector(&line, 0, 0))
		return (FALSE);
	if (!check_double(&line, 0, 0))
		return (FALSE);
	if (!check_vector(&line, 0, 255))
		return (FALSE);
	while (check_whitespace(line))
		line++;
	if (*line != 0)
		return (FALSE);
	return (TRUE);
}

t_bool	check_plane(char *line)
{
	line++;
	line++;
	if (!check_vector(&line, 0, 0))
		return (FALSE);
	if (!check_vector(&line, -1, 1))
		return (FALSE);
	if (!check_vector(&line, 0, 255))
		return (FALSE);
	while (check_whitespace(line))
		line++;
	if (*line != 0)
		return (FALSE);
	return (TRUE);
}
