/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:42:58 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/03 15:36:08 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

void	ft_fork(t_philo *p, unsigned long long time)
{
	sem_wait(p->d.pr);
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(p->id);
	ft_putchar(' ');
	ft_print("has taken a fork\n");
	sem_post(p->d.pr);
}

void	ft_eating(t_philo *p, unsigned long long time)
{
	sem_wait(p->d.pr);
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(p->id);
	ft_putchar(' ');
	ft_print("is eating\n");
	sem_post(p->d.pr);
}

void	ft_sleeping(t_philo *p, unsigned long long time)
{
	sem_wait(p->d.pr);
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(p->id);
	ft_putchar(' ');
	ft_print("is sleeping\n");
	sem_post(p->d.pr);
}

void	ft_thinking(t_philo *p, unsigned long long time)
{
	if (ft_is_alive(p))
	{
		sem_wait(p->d.pr);
		ft_putnbr(time);
		ft_putchar(' ');
		ft_putnbr(p->id);
		ft_putchar(' ');
		ft_print("is thinking\n");
		sem_post(p->d.pr);
	}
}

void	ft_dead(t_philo *p, unsigned long long time)
{
	sem_wait(p->d.pr);
	ft_putnbr(time);
	ft_putchar(' ');
	ft_putnbr(p->id);
	ft_putchar(' ');
	ft_print("is Dead\n");
	sem_wait(p->d.m_dead);
	p->d.dead = 1;
	sem_post(p->d.m_dead);
	exit(1);
	return ;
}
