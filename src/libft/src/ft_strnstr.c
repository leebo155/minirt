/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:27:04 by bohlee            #+#    #+#             */
/*   Updated: 2023/04/06 14:02:43 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_needlecmp(const char *haystack, const char *needle)
{
	size_t	index;

	index = 0;
	while (needle[index])
	{
		if (haystack[index] != needle[index] || haystack[index] == '\0')
			return (0);
		index++;
	}
	return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	needle_length;

	index = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	needle_length = ft_strlen(needle) - 1;
	while (haystack[index] && index + needle_length < len)
	{
		if (haystack[index] == needle[0])
		{
			if (ft_needlecmp(&haystack[index], needle))
				return (&((char *)haystack)[index]);
		}
		index++;
	}
	return (0);
}
