/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:39:31 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/24 13:11:39 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		index;
	char		*dst_arr;
	const char	*src_arr;

	dst_arr = dst;
	src_arr = src;
	index = 0;
	if (dst == 0 && src == 0)
		return (0);
	else if (dst <= src)
	{
		while (index < len)
		{
			dst_arr[index] = src_arr[index];
			index++;
		}
	}
	else
	{
		while (len - index++ > 0)
			dst_arr[len - index] = src_arr[len - index];
	}
	return (dst);
}
