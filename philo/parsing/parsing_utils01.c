/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:10:25 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/06 16:23:02 by zmakhkha         ###   ########.fr       */
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
		return (1);
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (1);
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
		if (ft_isnumber(v[i]) || ft_latoi(v[i]) < 0)
			return (1);
	}
	return (0);
}

int	main_parsing(int n, char **v)
{
	if (n < 5 || n > 6 || ft_check_args(n, v))
		return (1);
	return (0);
}
