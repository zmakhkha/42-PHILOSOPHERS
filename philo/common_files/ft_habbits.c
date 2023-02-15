/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_habbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:37:06 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/15 18:05:23 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_sleep(t_philo *p)
{
	printf("%lu : %d is sleep\n",ft_stime(U_S), p->id);
	ft_usleep(p->t_sleep);
}

void	ft_take_fork(t_philo *p)
{
	t_philo	*l;

	l = p;
	pthread_mutex_lock(&(l->r_fork));
	printf("%lu : %d taken a R_fork\n",ft_stime(U_S), l->id);
	if (ft_is_alive(p))
	{	
		pthread_mutex_lock(&(l-> prev ->r_fork));
		printf("%lu : %d taken a L_fork\n",ft_stime(U_S), l->id);
		ft_eat(p);
		ft_set_lmeat(p);
		pthread_mutex_unlock(&(l->r_fork));
		pthread_mutex_unlock(&(l-> prev ->r_fork));
	}
	else
	{
		ft_kill_all(p);
	}
}

void	ft_eat(t_philo *p)
{
	t_philo	*l;

	l = p;
	pthread_mutex_lock(&(l->pr));
	printf("%lu : %d is eating\n",ft_stime(U_S), p->id);
	pthread_mutex_unlock(&(l->pr));
	ft_usleep(p ->t_sleep);
}

void	ft_routin(t_philo *p)
{
	int	i;

	i = p->n_meat;
	while (i--)
	{
		if (!ft_is_alive(p))
		{
			ft_kill_all(p);
			return;
		}
		ft_take_fork(p);
		ft_sleep(p);
		printf("%lu : %d is thinking\n",ft_stime(U_S), p->id);
	}
}
