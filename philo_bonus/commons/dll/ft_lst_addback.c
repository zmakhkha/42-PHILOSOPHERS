/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:31:35 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/05 14:55:43 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../philo_bonus.h"

void	ft_lstadd_back(t_philo **lst, t_philo *new)
{
	t_philo	*pos;

	if (*lst == NULL)
		*lst = new;
	else
	{
		pos = *lst;
		while (pos -> prev != NULL)
			pos = pos -> prev;
		pos -> prev = new;
		new ->next = pos;
	}
}
