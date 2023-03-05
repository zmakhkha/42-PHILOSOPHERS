/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 15:57:57 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/05 17:52:22 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print(char *c)
{
	write(1, c, ft_strlen(c));
}

void	ft_putnbr(int n)
{
	if (n > 9)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

// void	ft_stat(t_philo *p, unsigned long time, int action)
// {
// 	pthread_mutex_lock(&(p->d->pr));
// 	ft_putnbr(time);
// 	ft_putchar(' ');
// 	ft_putnbr(p->id);
// 	ft_putchar(' ');
// 	if (!action)
// 		ft_print("has taken a fork\n");
// 	else if (action == 1)
// 		ft_print("is eating\n");
// 	else if (action == 2)
// 	{
// 		ft_print("is sleeping\n");
// 		ft_usleep(p->d->t_sleep);
// 	}
// 	else if (action == 3)
// 		ft_print("is thinking\n");
// 	else if (action == 4)
// 	{
// 		ft_print("is Dead\n");
// 		p ->d->dead = 1;
// 		return ;
// 	}
// 	pthread_mutex_unlock(&(p->d->pr));
// }
