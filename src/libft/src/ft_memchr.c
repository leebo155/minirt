/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:00:31 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/25 15:39:46 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*str;
	size_t				index;

	str = s;
	index = 0;
	while (index < n)
	{
		if (str[index] == (unsigned char)c)
			return (&((void *)s)[index]);
		index++;
	}
	return (0);
}
