/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:30:40 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/20 19:38:32 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

//int	ft_is_alive(t_philo *p)
//{
//	if (p -> l_eat + p -> l_sleep < p -> t_alive)
//		return (1);
//	else
//		return (0);
//}

t_data	*ft_fill_it(int n, char **v)
{
	t_data	*p;

	p = (t_data *)malloc (sizeof(t_data));
	p -> n_philo = ft_latoi(v[1]);
	p -> t_alive = ft_latoi(v[2]);
	p -> t_eat = ft_latoi(v[3]);
	p -> t_sleep = ft_latoi(v[4]);
	p -> inf = 0;
	if (n == 6)
	{
		p -> n_meat = ft_latoi(v[5]);
		p -> inf = 1;
	}
	return (p);
}

// Retun the moment in ms

unsigned long	ft_moment(unsigned long s)
{
	unsigned long	e;

	e = ft_stime();
	if (e - s > 0)
		return ((e - s) / 1000);
	else
		return (-1);
}

void	ft_shphilo(t_philo **p, t_data *d)
{
	t_philo	*t;
	int		i;

	i = 0;
	t = *p;
	while (++i < d->n_philo)
	{
		t->d = d;
		t = t->prev;
	}
}
