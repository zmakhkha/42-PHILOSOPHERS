/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:23:13 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/26 01:28:43 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

void	ft_routine(t_data *shared, int id)
{
	int	l_fork;
	int	r_fork;
	int	i;

	l_fork = id;
	r_fork = id % shared->n_philo;
	i = -1;
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
