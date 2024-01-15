/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unit_minimum.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:40:57 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/10 17:40:16 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	vunit(t_vec3 vec)
{
	double	length;

	length = vec_length(vec);
	vec.x /= length;
	vec.y /= length;
	vec.z /= length;
	return (vec);
}

t_vec3	vmin(t_vec3 vec1, t_vec3 vec2)
{
	if (vec1.x > vec2.x)
		vec1.x = vec2.x;
	if (vec1.y > vec2.y)
		vec1.y = vec2.y;
	if (vec1.z > vec2.z)
		vec1.z = vec2.z;
	return (vec1);
}

double	vec_pow(t_vec3 vec)
{
	return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vec_length(t_vec3 vec)
{
	return (sqrt(vec_pow(vec)));
}
