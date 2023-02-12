/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:30:40 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/12 17:39:22 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	ft_is_alive(t_philo *p)
{
	if (p -> l_eat + p -> l_sleep < p -> t_alive)
		return (1);
	else
		return (0);
}
