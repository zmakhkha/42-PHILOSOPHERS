/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sems.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:24:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/26 22:04:27 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

void	ft_create_forks(t_data *shared)
{
	int	i;

	shared->forks = (sem_t *)malloc(sizeof(sem_t) * shared->n_philo);
	if (!shared->forks)
		ft_exit("Allocation Failed !!", 1);
	i = -1;
	while (++i < shared->n_philo)
	{
		if (sem_open(FORKS, O_CREAT, 0644, 1) == SEM_FAILED)
		{
			// should free the allocated memory
			ft_exit("Semaphore yaaaaa wld hnini !!", 1);
		}
	}
}

void	ft_create_philo(t_data *shared)
{
	int		i;
	pid_t	id;

	i = -1;
	while (++i < shared->n_philo)
	{
		id = fork();
		if (id < 0)
		{
			// should free the allocated memory
			ft_exit("Mochkil fel fork yaaa wld hnini", 1);
		}
		else if (id == 0)
			ft_routine(shared, i);
	}
}

void	ft_destroy(t_data *data)
{
	int		i;

	// Close and unlink
	i = -1;
	while (++i < data->n_philo)
	{
		sem_close(&data->forks[i]);
		sem_unlink(FORKS);
	}
	// Destroy
	i = -1;
	free(data->forks);
}
