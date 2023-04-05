/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:18:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/05 14:20:09 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"common_files/philo.h"

t_data	*ft_ini_data(int n, char **v)
{
	t_data			*data;

	data = NULL;
	if (!main_parsing(n, v))
	{
		data = ft_fill_it(n, v);
		if (data)
		{
			data ->dead = 0;
			data -> t_meat = data ->n_philo * data -> n_meat;
		}
	}
	return (data);
}

static int	ft_main(t_data *shared, t_philo *lst)
{
	int	i;

	i = -1;
	shared->s_t = ft_stime();
	while (++i < shared->n_philo)
	{
		if (pthread_create(&(lst ->philo), NULL, ft_begin, lst))
			return (1);
		lst = lst -> prev;
	}
	while (1)
	{
		usleep(100);
		if (shared->dead || (!shared->t_meat && !shared->inf))
			break ;
	}
	return (0);
}

int	main(int n, char **v)
{
	t_philo			*lst;
	t_data			*shared;
	int				i;

	shared = ft_ini_data(n, v);
	if (!shared)
		return (ft_print("Error !!!"), 1);
	lst = NULL;
	ft_ini_lst(&lst, shared);
	if (!lst)
		return (ft_print("Error !!!"), 1);
	if (ft_main(shared, lst))
		return (1);
	i = -1;
	while (++i < shared->n_philo)
	{
		pthread_detach(lst->philo);
		lst = lst->prev;
	}	
	return (0);
}
