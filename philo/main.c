/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:18:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/25 19:29:43 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"common_files/philo.h"

void	ft_died(t_philo *data)
{
	data -> d -> dead = 1;
}

t_data	*ft_ini_data(int n, char **v)
{
	t_data			*data;

	data = NULL;
	if (!main_parsing(n, v))
	{
		data = ft_fill_it(n, v);
		data ->dead = 0;
	}
	return (data);
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
	i = 0;
	shared->s_t = ft_stime();
	while (i < shared->n_philo)
	{
		lst->l_eat = shared->s_t;
		lst->l_sleep = shared->s_t;
		if (pthread_create(&(lst ->philo), NULL, ft_begin, lst))
			return (1);
		lst = lst -> prev;
		i++;
	}
	while (1)
	{
		if (shared->dead)
			break ;
	}
	return (0);
}
