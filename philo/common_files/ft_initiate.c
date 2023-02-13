/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:24:24 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/13 20:14:26 by zmakhkha         ###   ########.fr       */
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

void	ft_initiate(t_philo **p, t_data *d)
{
	t_philo	*l;
	int		i;

	l = *p;
	i = -1;
	while (++i < d->n_philo)
	{
		l -> n_meat = 10000;
		l -> start = d->s_t;
		l -> t_eat = 200;
		l -> l_eat = d->s_t;
		l -> t_sleep = 50;
		l -> l_sleep = d->s_t;
		l -> died = 0;
		l -> t_alive = 300;
		l -> t_think = 0;
		l -> n_philo = d->n_philo;
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
	while (++i < d->n_philo) // atoi hna
		ft_lstadd_back(p, ft_lstnew());
	l = *p;
	ft_enumerate(p);
	ft_circulare(p);
	ft_initiate(p, d);
}
