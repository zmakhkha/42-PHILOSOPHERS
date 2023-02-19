/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:24:24 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/19 19:08:30 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	*ft_begin(void *p)
{
	t_philo	*a;

	a = (t_philo *) p;
	if (a->d->n_philo == 1)
	{
		ft_kill_one(a);
		return (NULL);
	}
	if ((a->id % 2) == 0)
		usleep(a->d->t_eat);
	ft_routin(a);
	return (NULL);
}

void	ft_fill_philo(t_philo **p, t_data *d)
{
	t_philo	*l;
	int		i;

	l = *p;
	i = -1;
	while (++i < d->n_philo)
	{
		l -> l_eat = d->s_t;
		l -> l_sleep = d->s_t;
		l -> d = d;
		pthread_mutex_init(&(l -> r_fork), NULL);
		pthread_mutex_init(&(l -> pr), NULL);
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
