/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_vector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 16:15:18 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/13 14:15:09 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "valid.h"

double	ddouble(char **line)
{
	double	ret;

	while (check_whitespace(*line))
		(*line)++;
	my_atod(line, &ret);
	return (ret);
}

t_vec3	vvector(char **line)
{
	double	x;
	double	y;
	double	z;
	t_vec3	ret;

	x = ddouble(line);
	while (check_whitespace(*line))
		(*line)++;
	if (**line == ',')
		(*line)++;
	y = ddouble(line);
	while (check_whitespace(*line))
		(*line)++;
	if (**line == ',')
		(*line)++;
	z = ddouble(line);
	ret = vec3(x, y, z);
	return (ret);
}
