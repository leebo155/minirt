/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:17:42 by bohlee            #+#    #+#             */
/*   Updated: 2023/05/14 15:09:15 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*result;
	size_t	index;

	if (s1 == 0)
		return (0);
	index = 0;
	while (s1[index])
		index++;
	result = (char *)malloc(sizeof(char) * (index + 1));
	if (result == 0)
		return (0);
	index = 0;
	while (s1[index])
	{
		result[index] = s1[index];
		index++;
	}
	result[index] = '\0';
	return (result);
}
