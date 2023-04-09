/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 14:32:54 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/09 14:30:09 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo_bonus.h"

// Check if its a valid number
int	ft_isnumber(char *number)
{
	int	i;

	i = 0;
	if (number[0] == '+')
		i++;
	if (!number[i])
		return (1);
	while (number[i])
	{
		if (!ft_isdigit(number[i]))
			return (ERR);
		i++;
	}
	return (SUCC);
}

// Check the arguments validity
int	ft_valid_args(int n, char **v)
{
	int	stat;

	stat = SUCC;
	if (n == 6)
	{
		if (ft_isnumber(v[1]) || ft_isnumber(v[2]) || \
		ft_isnumber(v[3]) || ft_isnumber(v[4]) || \
		ft_isnumber(v[5]))
			stat = ERR;
	}
	if (n == 5)
	{
		if (ft_isnumber(v[1]) || ft_isnumber(v[2]) || \
		ft_isnumber(v[3]) || ft_isnumber(v[4]))
			stat = ERR;
	}
	return (stat);
}

// Initiate the semaphores
void	ft_initsem(t_data *data)
{
	data->pr = sem_open(PRINT, O_CREAT | O_EXCL, 0777, 1);
	if (data->pr == SEM_FAILED)
	{
		sem_unlink(PRINT);
		sem_close(data->pr);
		data->pr = sem_open(PRINT, O_CREAT | O_EXCL, 0777, 1);
		if (data->pr == SEM_FAILED)
			perror("mockila hadi");
	}
	data->forks = sem_open(FORKS, O_CREAT | O_EXCL, 0777, data->n_philo);
	if (data->forks == SEM_FAILED)
	{
		sem_unlink(FORKS);
		sem_close(data->forks);
		data->forks = sem_open(FORKS, O_CREAT | O_EXCL, 0777, data->n_philo);
		if (data->forks == SEM_FAILED)
			perror("mockila hadi");
	}
}

// parse the input and return a valid struct of the args
t_data	*ft_main_parsing(int n, char **v)
{
	t_data	*data;

	data = NULL;
	data = malloc(sizeof(t_data));
	if (!data)
		ft_exit("ALLOCATION PROBLEM !!", 1);
	if (n < 5 || n > 6)
		ft_exit("Wrong Parameters !!", 1);
	if (ft_valid_args(n, v) == ERR)
		ft_exit("Arguments problem !!", 1);
	data -> n_philo = ft_latoi(v[1]);
	data -> t_alive = ft_latoi(v[2]);
	data -> t_eat = ft_latoi(v[3]);
	data -> t_sleep = ft_latoi(v[4]);
	data -> n_meat = -1;
	ft_initsem(data);
	data->inf = 1;
	if (n == 6)
	{
		data->n_meat = 0;
		data->n_meat = ft_latoi(v[5]);
	}
	data -> phil = malloc(data->n_philo * sizeof(pid_t));
	return (data);
}
