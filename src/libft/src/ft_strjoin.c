/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:58:55 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/23 12:36:46 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	index;
	size_t	length;
	char	*result;

	length = ft_strlen(s1);
	length += ft_strlen(s2);
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result == 0)
		return (0);
	index = 0;
	while (s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	length = index;
	index = 0;
	while (s2[index])
		result[length++] = s2[index++];
	result[length] = '\0';
	return (result);
}
