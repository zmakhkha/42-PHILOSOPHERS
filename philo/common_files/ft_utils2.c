/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:30:40 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/09 08:20:57 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

static void	ft_init_mutex(t_data *p)
{
	int		a;

	a = 0;
	a = pthread_mutex_init(&(p->pr), NULL);
	if (a)
	{
		pthread_mutex_destroy(&(p->pr));
		pthread_mutex_init(&(p->pr), NULL);
	}
	a = pthread_mutex_init(&(p->m_dead), NULL);
	if (a)
	{
		pthread_mutex_destroy(&(p->m_dead));
		pthread_mutex_init(&(p->m_dead), NULL);
	}
}

t_data	*ft_fill_it(int n, char **v)
{
	t_data	*p;

	p = (t_data *)malloc (sizeof(t_data));
	if (!p)
		return (NULL);
	p -> n_philo = ft_latoi(v[1]);
	p -> t_alive = ft_latoi(v[2]);
	p -> t_eat = ft_latoi(v[3]);
	p -> t_sleep = ft_latoi(v[4]);
	p -> inf = 1;
	p -> n_meat = -1;
	ft_init_mutex(p);
	if (n == 6)
	{
		p -> n_meat = ft_latoi(v[5]);
		p -> inf = 0;
	}
	return (p);
}

// Retun the moment in ms

int	ft_moment(t_philo *p)
{
	return ((ft_stime() - p->d->s_t) / 1000);
}

void	ft_shphilo(t_philo **p, t_data *d)
{
	t_philo	*t;
	int		i;

	i = 0;
	t = *p;
	while (++i < d->n_philo)
	{
		t->d = d;
		t = t->prev;
	}
}

int	ft_is_alive(t_philo *p)
{
	return (((ft_stime() - p -> l_eat) <= p ->d->t_alive * 1000));
}
