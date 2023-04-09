/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:41:20 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/09 03:25:55 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo_bonus.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char *c)
{
	write(1, c, ft_strlen(c));
}

void	ft_putnbr(long long n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

size_t	ret_nbr(char *tmp)
{
	int				i;
	unsigned long	res;

	i = 0;
	res = 0;
	while (ft_isdigit(tmp[i]))
	{
		res += tmp[i] - 48 ;
		if (ft_isdigit(tmp[i + 1]))
			res = res * 10;
		if (!ft_isdigit(tmp[i + 1]))
			return (res);
		i++;
	}
	return (res);
}

long long	ft_latoi(const char *str)
{
	char	*tmp;
	int		i;

	tmp = (char *) str;
	i = 0;
	while ((tmp[i] >= 9 && tmp[i] <= 13) || tmp[i] == 32)
		i++;
	if (ft_isdigit(tmp[i]))
		return (ret_nbr(tmp + i));
	if (((tmp[i] == '+') || (tmp[i] == '-')) && ft_isdigit(tmp[i +1]))
	{
		if (tmp[i] == '-' && ft_isdigit(tmp[i + 1]))
			return (-1 * ret_nbr(tmp + i + 1));
		else if (tmp[i] == '+')
			return (ret_nbr(tmp + i + 1));
		else
			return (0);
	}
	return (0);
}
