/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:36:45 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/25 16:33:30 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			index;
	unsigned char	*arr;

	index = 0;
	arr = b;
	while (index < len)
	{
		arr[index] = (unsigned char)c;
		index++;
	}
	return (b);
}
