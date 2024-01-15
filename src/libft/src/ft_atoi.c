/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bohlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:13:31 by bohlee            #+#    #+#             */
/*   Updated: 2023/04/06 13:57:48 by bohlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_islonglong(const char *str, int minus)
{
	char	*max;
	char	*min;
	char	*abs;
	int		result;
	int		index;

	max = "9223372036854775807";
	min = "9223372036854775808";
	result = 0;
	index = 0;
	abs = max;
	if (minus == -1)
		abs = min;
	else
		result = -1;
	while (abs[index])
	{
		if (str[index] > abs[index])
			return (result);
		index++;
	}
	return (1);
}

static int	ft_isminus(const char *str, int	*index)
{
	int	nflag;

	nflag = 1;
	if (str[*index] == '-' || str[*index] == '+')
	{
		if (str[(*index)++] == '-')
			nflag *= -1;
	}
	return (nflag);
}

int	ft_atoi(const char *str)
{
	int					index;
	int					count;
	int					nflag;
	int					except;	
	unsigned long long	result;	

	index = 0;
	count = 0;
	result = 0;
	while ((9 <= str[index] && str[index] <= 13) || str[index] == 32)
		index++;
	nflag = ft_isminus(str, &index);
	while ('0' <= str[index] && str[index] <= '9')
	{
		result = (result * 10) + (str[index++] - '0');
		if (count++ >= 18)
		{
			except = ft_islonglong(&str[index - count], nflag);
			if (except != 1)
				return (except);
		}
	}
	return ((long long)result * nflag);
}
