/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:36:06 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/12 17:37:13 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../philo.h"

void	ft_enumerate(t_philo **p)
{
	t_philo	*l;
	int		i;

	i = 0;
	l = *p;
	while (l)
	{
		l ->id = ++i;
		l = l -> prev;
	}
}

void	ft_circulare(t_philo **p)
{
	t_philo	*l;
	t_philo	*end;

	l = *p;
	end = ft_lst_get_end(l);
	l -> next = end;
	end -> prev = l;
}
