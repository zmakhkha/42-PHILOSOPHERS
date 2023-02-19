/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:30:40 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/19 19:04:51 by zmakhkha         ###   ########.fr       */
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

int	ft_moment(unsigned long s, unsigned long e)
{
	return ((e - s) / 1000);
}

// void	ft_ini_shared(t_data **d)
// {
// 	t_data	*data;

// 	data = *d;
// 	data ->dead = 0;
// 	data ->s_t = ft_stime(U_S);
// }

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

// void	ft_ps(t_philo *p, int s)
// {
// 	pthread_mutex_lock(&(p->pr));
// 	ft_putnbr(ft_moment(p->d->s_t));
// 	ft_putchar(' ');
// 	ft_putnbr(p->id);
// 	if(!s)
// 	{
// 		p->d->n_meat--;
// 		ft_print(" is eating\n");
// 	}
// 	else if (s == 1)
// 		ft_print(" is sleeping\n");
// 	else if (s == 2)
// 		ft_print(" is thinking\n");
// 	else if (s == 3)
// 		ft_print(" died\n");
// 	else if (s == 4)
// 		ft_print(" has taken a fork\n");
// 	pthread_mutex_unlock(&(p->pr));
// }