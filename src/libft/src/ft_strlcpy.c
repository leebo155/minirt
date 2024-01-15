/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 18:31:08 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/23 12:30:36 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_length;
	size_t	copy_length;
	size_t	index;

	src_length = 0;
	while (src[src_length])
		src_length++;
	if (dstsize == 0)
		return (src_length);
	if (src_length < dstsize)
		copy_length = src_length;
	else
		copy_length = dstsize - 1;
	dst[copy_length] = '\0';
	index = 0;
	while (index < copy_length)
	{
		dst[index] = src[index];
		index++;
	}
	return (src_length);
}
