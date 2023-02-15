/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_death.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:49:37 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/15 17:51:33 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_set_lmeat(t_philo *p)
{
	p -> l_eat = ft_stime(U_S);
}

int	ft_is_alive(t_philo *p)
{
	unsigned long	t;

	t = ft_stime(U_S);
	if (t - p -> l_eat <= p ->t_alive)
		return (1);
	return (0);
}

void	ft_kill_one(t_philo *p)
{
	pthread_mutex_lock(&(p->pr));
	printf("%lu : %d Died\n",ft_stime(U_S), p->id);
	pthread_mutex_lock(&(p->r_fork));
	p->dead = 1; 
	return;
}

void	ft_kill_all(t_philo *p)
{
	int	i;

	i = -1;
	while(++i < p->n_philo)
	{
		ft_kill_one(p);
		p = p->prev;
	}
}

int	ft_check_death(t_philo *p)
{
	int	i;

	i = -1;
	while(++i < p->n_philo)
	{
		if (!ft_is_alive(p))
			return (1);
	}
	return (0);
}
