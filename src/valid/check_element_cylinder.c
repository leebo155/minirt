/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_element_cylinder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 13:33:46 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/12 13:13:41 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid.h"

t_bool	check_cylinder(char *line)
{
	line++;
	line++;
	if (!check_vector(&line, 0, 0))
		return (FALSE);
	if (!check_vector(&line, -1, 1))
		return (FALSE);
	if (!check_double(&line, 0, 0))
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
