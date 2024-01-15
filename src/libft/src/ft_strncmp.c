/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 12:56:48 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/23 17:06:50 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			index;
	unsigned char	c1;
	unsigned char	c2;

	index = 0;
	while ((s1[index] || s2[index]) && index < n)
	{
		c1 = s1[index];
		c2 = s2[index];
		if (c1 != c2)
			return (c1 - c2);
		index++;
	}
	return (0);
}
