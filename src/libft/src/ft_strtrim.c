/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:39:19 by bohlee            #+#    #+#             */
/*   Updated: 2023/04/06 14:03:55 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char const s1, char const *set)
{
	size_t	index;

	index = 0;
	while (set[index])
	{
		if (s1 == set[index])
			return (1);
		index++;
	}
	return (0);
}

static char	*ft_malloctrim(char	const *s1, size_t length, size_t start)
{
	char	*result;
	size_t	s1_index;
	size_t	result_index;

	if (length == ft_strlen(s1))
		s1_index = 0;
	else
		s1_index = start;
	result_index = 0;
	result = (char *)malloc(sizeof(char) * (length + 1));
	if (result == 0)
		return (0);
	result[length] = '\0';
	while (result_index < length)
		result[result_index++] = s1[s1_index++];
	return (result);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	length;
	char	*result;

	start = 0;
	if (ft_strlen(s1) > 0)
		end = ft_strlen(s1) - 1;
	else
		end = 0;
	while (ft_checkset(s1[start], set) && s1[start])
		start++;
	while (end > 0 && ft_checkset(s1[end], set))
		end--;
	if (end >= start && !(end == 0 && start == 0))
		length = (end - start) + 1;
	else
		length = 0;
	result = ft_malloctrim(s1, length, start);
	if (result == 0)
		return (0);
	return (result);
}
