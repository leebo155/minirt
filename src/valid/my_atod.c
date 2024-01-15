/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:45:57 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/12 14:07:23 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid.h"

static t_bool	my_get_integer(char **line, double *ret, int *size)
{
	if (!ft_isdigit(**line))
		return (FALSE);
	while (ft_isdigit(**line))
	{
		*ret *= 10;
		*ret += **line - '0';
		(*line)++;
		if ((*size)++ > 15)
			return (FALSE);
	}
	return (TRUE);
}

static t_bool	my_get_fract(char **line, double *ret, int *size)
{
	char	*tmp_line;

	(*line)++;
	if (!ft_isdigit(**line))
		return (FALSE);
	while (ft_isdigit(**line))
	{
		(*size)++;
		(*line)++;
	}
	if (*size > 15)
		return (FALSE);
	tmp_line = *line;
	tmp_line--;
	while (ft_isdigit(*tmp_line))
	{
		*ret += *tmp_line - '0';
		*ret *= 0.1;
		tmp_line--;
	}
	return (TRUE);
}

t_bool	my_atod(char **line, double *ret)
{
	int		size;
	double	flag;
	double	integer_part;
	double	fractional_part;

	size = 0;
	flag = 1;
	*ret = 0;
	integer_part = 0;
	fractional_part = 0;
	if (**line == '-')
	{
		flag = -1;
		(*line)++;
	}
	if (!my_get_integer(line, &integer_part, &size))
		return (FALSE);
	if (**line == '.' && !my_get_fract(line, &fractional_part, &size))
		return (FALSE);
	*ret = (integer_part + fractional_part) * flag;
	return (TRUE);
}
