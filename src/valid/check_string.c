/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:11:00 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/13 14:45:56 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid.h"

t_bool	check_whitespace(char *line)
{
	if ((9 <= *line && *line <= 13) || *line == 32)
		return (TRUE);
	return (FALSE);
}

t_bool	check_empty_line(char *line)
{
	while (check_whitespace(line))
		line++;
	if (*line == 0)
		return (TRUE);
	return (FALSE);
}

t_bool	check_double(char **line, double min, double max)
{
	double	num;

	while (check_whitespace(*line))
		(*line)++;
	if (**line == '-' || ft_isdigit(**line))
	{
		if (!my_atod(line, &num))
			return (FALSE);
		if (min != max && (num < min || max < num))
			return (FALSE);
		if (check_whitespace(*line) || **line == 0 || **line == ',')
			return (TRUE);
	}
	return (FALSE);
}

t_bool	check_vector(char **line, double min, double max)
{
	if (!check_double(line, min, max))
		return (FALSE);
	while (check_whitespace(*line))
		(*line)++;
	if (**line == ',')
		(*line)++;
	if (!check_double(line, min, max))
		return (FALSE);
	while (check_whitespace(*line))
		(*line)++;
	if (**line == ',')
		(*line)++;
	if (!check_double(line, min, max))
		return (FALSE);
	if (check_whitespace(*line) || **line == 0)
		return (TRUE);
	return (FALSE);
}
