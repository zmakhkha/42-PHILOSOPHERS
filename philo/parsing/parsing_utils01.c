/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:10:25 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/17 19:00:24 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../common_files/philo.h"

int	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	if (number[0] == '+')
		i++;
	if (!number[i])
	{
		free (number);
		return (1);
	}
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
		{
			free (number);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_check_args(int n, char **v)
{
	int	i;

	i = 0;
	while (++i < n)
	{
		if (ft_isnumber(v[i]))
			return (1);
	}
	return (0);
}

int	main_parsing(int n, char **v)
{
	if (n < 5 || n > 6)
		return (1);
	else
	{
		if (!ft_check_args(n, v))
			return (0);
	}
	return (0);
}
