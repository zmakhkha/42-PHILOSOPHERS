/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:23:13 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/28 22:07:09 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

void	ft_eat(t_philo *p)
{
	int	n;

	n = p->d->n_philo;
	sem_wait(&p->d->forks[p->id % n]);
	if (ft_is_alive(p))
	{
		sem_wait(&p->d->forks[(p->id + 1) % n]);
		p->l_eat = ft_stime();
		ft_eating(p, ft_moment(p));
		ft_usleep(p ->d->t_eat);
		p->d->t_meat--;
		sem_post(&p->d->forks[(p->id + 1) % n]);
		sem_post(&p->d->forks[p->id % n]);
	}
}

void	ft_routine(t_philo *p)
{
	p->l_eat = p->d->s_t;
	p->l_sleep = p->d->s_t;
	if (p->d->n_philo == 1)
	{
		ft_dead(p, ft_moment(p));
		return;
	}
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
}
