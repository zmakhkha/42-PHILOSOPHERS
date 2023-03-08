/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:42:58 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/08 13:53:29 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_fork(t_philo *p, unsigned long long time)
{
	pthread_mutex_lock(&(p->d->pr));
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(p->id);
	ft_putchar(' ');
	ft_print("has taken a fork\n");
	pthread_mutex_unlock(&(p->d->pr));
}

void	ft_eating(t_philo *p, unsigned long long time)
{
	pthread_mutex_lock(&(p->d->pr));
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(p->id);
	ft_putchar(' ');
	ft_print("is eating\n");
	pthread_mutex_unlock(&(p->d->pr));
}

void	ft_sleeping(t_philo *p, unsigned long long time)
{
	pthread_mutex_lock(&(p->d->pr));
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(p->id);
	ft_putchar(' ');
	ft_print("is sleeping\n");
	pthread_mutex_unlock(&(p->d->pr));
}

void	ft_thinking(t_philo *p, unsigned long long time)
{
	if (ft_is_alive(p))
	{
		pthread_mutex_lock(&(p->d->pr));
		ft_putnbr(time);
		ft_putchar(' ');
		ft_putnbr(p->id);
		ft_putchar(' ');
		ft_print("is thinking\n");
		pthread_mutex_unlock(&(p->d->pr));
	}
}

void	ft_dead(t_philo *p, unsigned long long time)
{
	pthread_mutex_lock(&(p->d->pr));
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(p->id);
	ft_putchar(' ');
	ft_print("is Dead\n");
	pthread_mutex_lock(&(p->d->m_dead));
	p->d->dead = 1;
	pthread_mutex_unlock(&(p->d->m_dead));
	return ;
}
