/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_habbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:37:06 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/27 19:40:52 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_eat(t_philo *p)
{
	pthread_mutex_lock(&(p->r_fork));
	ft_stat(p, ft_moment(p->d->s_t), FORK);
	if (ft_is_alive(p))
	{
		pthread_mutex_lock(&(p-> prev ->r_fork));
		ft_stat(p, ft_moment(p->d->s_t), FORK);
		ft_stat(p, ft_moment(p->d->s_t), EAT);
		p->d->t_meat--;
		ft_usleep(p ->d->t_eat);
		p->l_eat = ft_stime();
		pthread_mutex_unlock(&(p-> prev ->r_fork));
		pthread_mutex_unlock(&(p->r_fork));
	}
}

void	*ft_begin(void *a)
{
	t_philo	*p;

	p = (t_philo *) a;
	if (p->d->n_philo == 1)
	{
		ft_stat(p, ft_moment(p->d->s_t), DIE);
		return (NULL);
	}
	if ((p->id % 2) == 0)
		usleep(1000);
	while (ft_is_alive(p))
	{
		ft_eat(p);
		if (ft_is_alive(p))
			ft_stat(p, ft_moment(p->d->s_t), SLEEP);
		if (ft_is_alive(p))
		{
			ft_stat(p, ft_moment(p->d->s_t), THINK);
			continue ;
		}
	}
	ft_stat(p, ft_moment(p->d->s_t), DIE);
	return (NULL);
}
