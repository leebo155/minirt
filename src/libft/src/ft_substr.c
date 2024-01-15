/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:37:58 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/24 12:43:45 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	length;
	size_t	index;

	index = 0;
	length = ft_strlen(s);
	if (length < start + len)
	{
		if (length < start)
			result = (char *)malloc(sizeof(char) * 1);
		else
			result = (char *)malloc(sizeof(char) * ((length - start) + 1));
	}
	else
		result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	while ((start + index < length) && index < len)
	{
		result[index] = s[start + index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
