/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:10:25 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/31 08:57:31 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

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
t_data	ft_parse_it(int n, char **v)
{
	t_data	data;

	if (n < 5 || n > 6)
		ft_exit("Wrong Parameters !!", 1);
	if (ft_valid_args(n, v) == ERR)
		ft_exit("Arguments problem !!", 1);
	data.n_philo = ft_latoi(v[1]);
	data.t_alive = ft_latoi(v[2]);
	data.t_eat = ft_latoi(v[3]);
	data.t_sleep = ft_latoi(v[4]);
	ft_initsem(&data);
	if (n == 6)
		data.n_meat = ft_latoi(v[5]);
	data.s_t = ft_stime();
	return (data);
}

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
