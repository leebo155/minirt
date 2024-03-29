/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:55:17 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/23 12:16:47 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	index;
	char	*arr;

	index = 0;
	arr = s;
	while (index < n)
	{
		arr[index] = 0;
		index++;
	}
}
