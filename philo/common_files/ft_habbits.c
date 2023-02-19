/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_habbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:37:06 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/19 19:09:33 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_sleep(t_philo *p)
{
	pthread_mutex_lock(&(p->pr));
	printf("%d %d is sleeping\n", ft_moment(p->d->s_t, \
		ft_stime(U_S)), p->id);
	ft_usleep(p->d->t_sleep * 1000);
	pthread_mutex_unlock(&(p->pr));
}

void	ft_think(t_philo *p)
{
	pthread_mutex_lock(&(p->pr));
	printf("%d %d is thinking\n", ft_moment(p->d->s_t, \
		ft_stime(U_S)), p->id);
	pthread_mutex_unlock(&(p->pr));
}

void	ft_take_fork(t_philo *p)
{
	pthread_mutex_lock(&(p->r_fork));
	pthread_mutex_lock(&(p->pr));
	printf("%d %d has taken a fork\n", ft_moment(p->d->s_t, \
		ft_stime(U_S)), p->id);
	pthread_mutex_unlock(&(p->pr));
	if (ft_is_alive(p))
	{	
		pthread_mutex_lock(&(p-> prev ->r_fork));
		pthread_mutex_lock(&(p->pr));
		printf("%d %d has taken a fork\n", ft_moment(p->d->s_t, \
			ft_stime(U_S)), p->id);
		printf("%d %d is eating\n", ft_moment(p->d->s_t, \
			ft_stime(U_S)), p->id);
		pthread_mutex_unlock(&(p->pr));
		p->d->n_meat--;
		ft_usleep(p ->d->t_eat * 1000);
		pthread_mutex_unlock(&(p-> prev ->r_fork));
		pthread_mutex_unlock(&(p->r_fork));
		p->l_eat = ft_stime(U_S);
	}
	else
		ft_kill_one(p);
}

void	ft_routin(t_philo *p)
{
	int	i;

	i = p ->d->n_meat;
	while (1)
	{
		ft_take_fork(p);
		ft_sleep(p);
		ft_think(p);
	}
}
