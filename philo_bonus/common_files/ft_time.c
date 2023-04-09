/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:46:26 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/09 11:50:35 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo_bonus.h"

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

// return the time from the epoch in us
unsigned long long	ft_stime(void)
{
	struct timeval		tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

int	ft_is_alive(t_philo *p)
{
	return (((ft_stime() - p -> l_eat) <= p->d->t_alive * 1000));
}

// Retun the moment in ms
int	ft_moment(t_philo *p)
{
	return ((ft_stime() - p->d->s_t) / 1000);
}
