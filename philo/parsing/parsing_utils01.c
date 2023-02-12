/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils01.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:10:25 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/12 17:36:26 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../common_files/philo.h"

void	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	if (number[0] == '-' || number[0] == '+')
		i++;
	if (!number[i])
	{
		free (number);
		ft_print_error("Error", 1);
	}
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
		{
			free (number);
			ft_print_error("Error", 1);
		}
		i++;
	}
}

void	main_parsing(int n, char **v)
{
	if (n != 6)
		ft_print_error("Error !!", 1);
	else
		ft_check_args(n, v);
}

void	ft_check_args(int n, char **v)
{
	int	i;

	i = 0;
	while (++i < n)
		ft_isnumber(v[i]);
}
