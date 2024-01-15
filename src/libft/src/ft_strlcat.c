/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:32:25 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/23 12:28:18 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_length;
	size_t	src_length;
	size_t	dst_index;
	size_t	src_index;

	dst_length = 0;
	src_length = 0;
	src_index = 0;
	while (dst[dst_length])
		dst_length++;
	dst_index = dst_length;
	while (src[src_length])
		src_length++;
	while (src[src_index] && (dst_length + src_index + 1) < dstsize)
		dst[dst_index++] = src[src_index++];
	dst[dst_index] = '\0';
	if (dst_length < dstsize)
		return (dst_length + src_length);
	else
		return (src_length + dstsize);
}
