/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:18:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/13 20:14:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"common_files/philo.h"

//void	ft_void(int n, char **v)
//{
//	(void)n;
//	(void)v;
//}

void	ft_died(t_philo *data)
{
	data -> died = 1;
}

int	ft_is_dead(t_philo *data)
{
	int	i;

	i = -1;
	while (++i < data -> n_philo)
	{
		if (data ->died)
			return (1);
	}
	return (0);
}

void	ft_join_t(t_philo *p, t_data *d)
{
	t_philo	*tmp;
	int		i;

	tmp = p;
	i = -1;
	while (++i < d->n_philo)
	{
		pthread_join((tmp->philo), NULL);
		tmp = tmp -> prev;
	}
}

t_data	*ft_ini_data(int n, char **v)
{
	t_data			*data;

	data = (t_data *)malloc(sizeof(t_data *));
	data -> n = n;
	data -> n_philo = 5;
	data -> v = v;
	data ->s_t = ft_get_start_time(U_S);
	return (data);
}

int	main(int n, char **v)
{
	t_philo			*lst;
	t_philo			*tmp;
	t_data			*d;
	int				i;

	lst = NULL;
	d = ft_ini_data(n, v);
	ft_ini_lst(&lst, d);
	tmp = lst;
	//main_parsing(n, v);
	i = -1;
	while (++i < d->n_philo)
	{
		if (pthread_create(&(lst ->philo), NULL, ft_begin, lst))
			return (1);
		lst = lst -> prev;
	}
	ft_join_t(tmp, d);
	return (0);
}
