/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <bohlee@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:23:15 by bohlee            #+#    #+#             */
/*   Updated: 2024/01/24 14:35:18 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "valid.h"

void	print_error(char *str)
{
	ft_putendl_fd("Error", STDERR);
	ft_putendl_fd(str, STDERR);
}

void	print_nbr_error(int nbr, char *str)
{
	ft_putendl_fd("Error", STDERR);
	ft_putnbr_fd(nbr, STDERR);
	ft_putendl_fd(str, STDERR);
}
