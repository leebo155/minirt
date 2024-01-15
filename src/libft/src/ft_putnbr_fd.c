/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:55:48 by bohlee            #+#    #+#             */
/*   Updated: 2023/03/23 18:13:47 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long long	number;

	number = n;
	if (n < 0)
	{
		number *= -1;
		ft_putchar_fd('-', fd);
	}
	if (number < 10)
	{
		ft_putchar_fd(number + '0', fd);
		return ;
	}
	ft_putnbr_fd(number / 10, fd);
	ft_putchar_fd(number % 10 + '0', fd);
}
