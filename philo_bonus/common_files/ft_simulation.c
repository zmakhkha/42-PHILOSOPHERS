/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_simulation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:07:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/09 13:25:09 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo_bonus.h"

void	ft_eat(t_philo *p)
{
	sem_wait(p->d->forks);
	ft_fork(p, ft_moment(p));
	if (ft_is_alive(p))
	{
		sem_wait(p->d->forks);
		ft_fork(p, ft_moment(p));
		p->l_eat = ft_stime();
		ft_eating(p, ft_moment(p));
		ft_usleep(p ->d->t_eat);
		p->d->t_meat++;
		if (p->d->n_meat == p->d->t_meat)
		{
			sem_post(p->d->forks);
			sem_post(p->d->forks);
			exit(0);
		}
		sem_post(p->d->forks);
		sem_post(p->d->forks);
	}
}

void	ft_routine(t_philo *p)
{
	while (ft_is_alive(p))
	{
		ft_eat(p);
		ft_sleeping(p, ft_moment(p));
		ft_thinking(p, ft_moment(p));
	}
	ft_dead(p, ft_moment(p));
}
