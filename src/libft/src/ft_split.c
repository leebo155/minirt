/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 13:51:14 by bohlee            #+#    #+#             */
/*   Updated: 2023/04/06 14:00:51 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_malloc_split_ptr(char const *s, char c)
{
	size_t	index;
	size_t	count;
	char	**result;

	index = 0;
	count = 0;
	while (s[index])
	{
		while (s[index] == c && s[index])
			index++;
		if (s[index])
			count++;
		while (s[index] != c && s[index])
			index++;
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (result == 0)
		return (0);
	result[count] = 0;
	return (result);
}

static char	*ft_malloc_split_str(char const *s, char c, size_t start)
{
	char	*result;
	size_t	s_index;
	size_t	size;
	size_t	result_index;

	s_index = start;
	size = 0;
	result_index = 0;
	while (s[s_index] != c && s[s_index])
	{
		s_index++;
		size++;
	}
	result = (char *)malloc(sizeof(char) * (size + 1));
	if (result == 0)
		return (0);
	s_index = start;
	while (s[s_index] != c && s[s_index])
		result[result_index++] = s[s_index++];
	result[result_index] = '\0';
	return (result);
}

static void	ft_freesplit(char **result, size_t strs)
{
	size_t	index;

	index = 0;
	if (strs == 0)
	{
		free(result);
		return ;
	}	
	else
		index = strs - 1;
	while (1)
	{
		free(result[index]);
		if (index == 0)
			break ;
		index--;
	}
	free(result);
}

char	**ft_split(char const *s, char c)
{
	size_t	s_index;
	size_t	result_index;
	char	**result;

	s_index = 0;
	result_index = 0;
	result = ft_malloc_split_ptr(s, c);
	if (result == 0)
		return (0);
	while (s[s_index])
	{
		while (s[s_index] == c && s[s_index])
			s_index++;
		if (s[s_index])
			result[result_index] = ft_malloc_split_str(s, c, s_index);
		if (result[result_index++] == 0 && s[s_index])
		{
			ft_freesplit(result, --result_index);
			return (0);
		}
		while (s[s_index] != c && s[s_index])
			s_index++;
	}
	return (result);
}
