/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:05:05 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/09 03:22:23 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo_bonus.h"

void	ft_fill_philo(t_philo **p, t_data *d)
{
	t_philo	*l;
	int		i;

	l = *p;
	i = -1;
	while (++i < d->n_philo)
	{
		l -> d = d;
		l = l -> prev;
	}		
}

void	ft_init_philo(t_philo **p, t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->n_philo)
		ft_lstadd_back(p, ft_lstnew());
	ft_enumerate(p);
	ft_circulare(p);
	ft_fill_philo(p, d);
}

void	ft_start(t_philo *p)
{
	p->d->s_t = ft_stime();
	p->l_eat = p->d->s_t;
	p->l_sleep = p->d->s_t;
	ft_routine(p);
}
