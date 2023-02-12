/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:24:24 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/12 18:05:17 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*ft_begin(void *p)
{
	t_philo	*a;

	a = (t_philo *) p;
	if ((a->id % 2) == 0)
		usleep(100);
	ft_routin(a);
	return (NULL);
}

void	ft_initiate(t_philo **p, unsigned long s)
{
	t_philo	*l;
	int		i;

	l = *p;
	i = -1;
	while (++i < 5)
	{
		l -> start = s;
		l -> t_eat = 200;
		l -> l_eat = s;
		l -> t_sleep = 50;
		l -> l_sleep = s;
		l -> died = 0;
		l -> t_alive = 300;
		l -> t_think = 0;
		pthread_mutex_init(&(l -> r_fork), NULL);
		pthread_mutex_init(&(l -> pr), NULL);
		l = l -> prev;
	}		
}
