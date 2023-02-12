/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_habbits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:37:06 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/12 18:13:46 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_sleep(t_philo *p)
{
	printf("%d is sleep\n", p->id);
	usleep(p->t_sleep);
}

void	ft_take_fork(t_philo *p)
{
	t_philo	*l;

	l = p;
	pthread_mutex_lock(&(l->r_fork));
	printf("%d taken a R_fork\n", l->id);
	pthread_mutex_lock(&(l-> prev ->r_fork));
	printf("%d taken a L_fork\n", l->id);
	ft_eat(p);
	pthread_mutex_unlock(&(l->r_fork));
	pthread_mutex_unlock(&(l-> prev ->r_fork));
}

void	ft_eat(t_philo *p)
{
	t_philo	*l;

	l = p;
	pthread_mutex_lock(&(l->pr));
	printf("%d is eating\n", p->id);
	pthread_mutex_unlock(&(l->pr));
	usleep(p ->t_sleep);
}

void	ft_routin(t_philo *p)
{
	int	i;

	i = 5;
	while (i--)
	{
		ft_take_fork(p);
		ft_sleep(p);
		printf("%d is thinking\n", p->id);
	}
}
