/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:25:47 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/23 16:59:10 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		index;
	char		*dst_arr;
	const char	*src_arr;

	index = 0;
	dst_arr = dst;
	src_arr = src;
	while (index < n && (dst != 0 || src != 0))
	{
		dst_arr[index] = src_arr[index];
		index++;
	}
	return (dst);
}
