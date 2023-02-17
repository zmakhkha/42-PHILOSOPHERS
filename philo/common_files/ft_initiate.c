/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:24:24 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/17 20:21:54 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*ft_begin(void *p)
{
	t_philo	*a;

	a = (t_philo *) p;
	if (a->n_philo == 1)
	{
		ft_kill_one(a);
		return (NULL);
	}
	if ((a->id % 2) == 0)
		ft_usleep(50);
	ft_routin(a);
	return (NULL);
}

void	ft_fill_philo(t_philo **p, t_data *d)
{
	t_philo	*l;
	int		i;

	l = *p;
	i = -1;
	l -> died = 0;
	while (++i < d->n_philo)
	{
		l -> died = 0;
		l -> n_meat = d->n_meat;
		l -> start = d->s_t;
		l -> t_eat = d->t_eat;
		l -> l_eat = d->s_t;
		l -> t_sleep = d->t_sleep;
		l -> l_sleep = d->s_t;
		l -> t_alive = d->t_alive;
		l -> t_think = 0;
		l -> inf = d -> inf;
		l -> n_philo = d->n_philo;
		pthread_mutex_init(&(l -> r_fork), NULL);
		pthread_mutex_init(&(l -> pr), NULL);
		pthread_mutex_init(&(l -> die), NULL);
		l = l -> prev;
	}		
}

void	ft_ini_lst(t_philo **p, t_data *d)
{
	t_philo	*l;
	int		i;

	i = -1;
	while (++i < d->n_philo)
		ft_lstadd_back(p, ft_lstnew());
	l = *p;
	ft_enumerate(p);
	ft_circulare(p);
	ft_fill_philo(p, d);
}
