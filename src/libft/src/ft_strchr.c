/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 13:28:51 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/24 12:22:32 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (s[index])
	{
		if (s[index] == (char)c)
			return (&((char *)s)[index]);
		index++;
	}
	if (s[index] == (char)c)
		return (&((char *)s)[index]);
	return (0);
}
