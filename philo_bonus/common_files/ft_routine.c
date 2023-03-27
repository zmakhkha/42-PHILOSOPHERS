/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:23:13 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/27 22:55:03 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

void	ft_eat(t_philo *philo)
{
	sem_wait(&shared->forks[l_fork]);
	if (ft_is_alive(philo))
	{
		sem_wait(&shared->forks[r_fork]);
		philo->l_eat = ft_stime;
		
	}
}

void	ft_routine(t_data *shared, int id)
{
	int	l_fork;
	int	r_fork;

	l_fork = id;
	r_fork = id % shared->n_philo;
	while (1)
	{
		sem_wait(&shared->forks[l_fork]);
		sem_wait(&shared->forks[r_fork]);
		printf("Philo %d is eating\n", id);
		sleep(2);
		sem_post(&shared->forks[r_fork]);
		sem_post(&shared->forks[l_fork]);
		printf("Philo %d is thinking\n", id);
		sleep(1);
	}
}
