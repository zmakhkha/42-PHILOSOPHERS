/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:30:40 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/26 01:35:46 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

// Retun the moment in ms
int	ft_moment(t_philo *p)
{
	return ((ft_stime() - p->d->s_t) / 1000);
}

// return the time from the epoch in us
unsigned long long	ft_stime(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

void	ft_usleep(unsigned long a)
{
	unsigned long long	t_daba;
	unsigned long long	t_alarm;
	unsigned long long	b;

	b = 0;
	t_daba = ft_stime();
	t_alarm = ft_stime() + (a * 1000);
	while (b < t_alarm)
	{
		usleep(100);
		b = ft_stime();
	}
}

int	ft_is_alive(t_philo *p)
{
	return (((ft_stime() - p -> l_eat) <= p ->d->t_alive * 1000));
}
