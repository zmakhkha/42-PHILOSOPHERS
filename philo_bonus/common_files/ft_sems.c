/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sems.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 01:24:09 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/28 23:13:26 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

void	ft_create_forks(t_philo *p)
{
	int	i;

	p->d = (sem_t *)malloc(sizeof(sem_t) * p->d->n_philo);
	if (!p->d->forks)
		ft_exit("Allocation Failed !!", 1);
	i = -1;
	while (++i < p->d->n_philo)
	{
		&(p->d->forks[i]) = sem_open(FORKS, 0644, 1);
		if (&p->d->forks[i] == SEM_FAILED)
		{
			// should free the allocated memory
			ft_exit("Semaphore yaaaaa wld hnini !!", 1);
		}
	}
}

void	ft_create_philo(t_data *shared, t_philo *p)
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
			ft_routine(shared, p);
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
