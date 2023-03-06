/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_habbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:37:06 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/06 16:00:51 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(&(p->r_fork));
	ft_fork(p, ft_moment(p));
	if (ft_is_alive(p))
	{
		pthread_mutex_lock(&(p-> prev ->r_fork));
		ft_fork(p, ft_moment(p));
		p->l_eat = ft_stime();
		ft_eating(p, ft_moment(p));
		ft_usleep(p ->d->t_eat);
		p->d->t_meat--;
		pthread_mutex_unlock(&(p-> prev ->r_fork));
		pthread_mutex_unlock(&(p->r_fork));
	}
}

void	*ft_begin(void *a)
{
	t_philo	*p;

	p = (t_philo *) a;
	p->l_eat = p->d->s_t;
	p->l_sleep = p->d->s_t;
	if (p->d->n_philo == 1)
	{
		ft_dead(p, ft_moment(p));
		return (NULL);
	}
	if ((p->id % 2) == 0)
		usleep(100);
	while (ft_is_alive(p))
	{
		ft_eat(p);
		if (ft_is_alive(p))
		{
			ft_sleeping(p, ft_moment(p));
			ft_usleep(p->d->t_sleep);
		}
		ft_thinking(p, ft_moment(p));
	}
	ft_dead(p, ft_moment(p));
	return (NULL);
}
