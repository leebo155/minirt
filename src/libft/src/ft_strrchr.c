/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:45:08 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/24 12:23:36 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	str_length;

	str_length = 0;
	while (s[str_length])
		str_length++;
	while (0 < str_length)
	{
		if (s[str_length] == (char)c)
			return (&((char *)s)[str_length]);
		str_length--;
	}
	if (s[str_length] == (char)c)
		return (&((char *)s)[str_length]);
	return (0);
}
