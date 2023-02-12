/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:56:50 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/12 17:44:21 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

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

unsigned long	ft_get_start_time(int t)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	if (!t)
		return (tv.tv_sec);
	else
		return (tv.tv_usec);
}

void	ft_usleep(unsigned long a)
{
	double	res;
	int		i;

	res = a / 20;
	i = -1;
	while (++i < 20)
		usleep(res);
}
