/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:25:44 by bohlee            #+#    #+#             */
/*   Updated: 2023/04/06 13:58:19 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(int n)
{
	long long	number;
	int			size;

	number = n;
	size = 1;
	if (n < 0)
	{
		number *= -1;
		size++;
	}
	while (number > 9)
	{
		number /= 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	long long	number;
	int			index;
	int			minus;
	char		*result;

	number = n;
	index = ft_get_size(n);
	minus = 0;
	result = (char *)malloc(sizeof(char) * (index + 1));
	if (result == 0)
		return (0);
	result[index--] = '\0';
	if (n < 0)
	{
		number *= -1;
		result[minus++] = '-';
	}
	while (index >= 0 + minus)
	{
		result[index--] = (number % 10) + '0';
		number /= 10;
	}
	return (result);
}
