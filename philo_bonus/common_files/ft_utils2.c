/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:43:53 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/05 14:45:16 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo_bonus.h"

int	ft_isdigit(int c)
{
	return ((48 <= c) && (c <= 57));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_print_error(char *str, int status)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit (status);
}

void	ft_exit(char *str, int stat)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", stat);
	exit(1);
}
