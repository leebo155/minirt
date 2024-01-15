/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:33:47 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/23 12:18:00 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	index;

	index = 0;
	result = (char *)malloc(count * size);
	if (result == 0)
		return (0);
	while (index < count * size)
	{
		result[index] = 0;
		index++;
	}
	return (result);
}
