/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_initiate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:24:24 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/06 15:54:17 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_fill_philo(t_philo **p, t_data *d)
{
	t_philo	*l;
	int		i;
	int		a;

	a = 0;
	l = *p;
	i = -1;
	while (++i < d->n_philo)
	{
		l -> d = d;
		a = pthread_mutex_init(&(l->r_fork), NULL);
		if (a)
		{
			pthread_mutex_destroy(&(l->r_fork));
			pthread_mutex_init(&(l->r_fork), NULL);
		}
		a = pthread_mutex_init(&(l->d->pr), NULL);
		if (a)
		{
			pthread_mutex_destroy(&(l->d->pr));
			pthread_mutex_init(&(l->d->pr), NULL);
		}
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
