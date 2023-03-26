/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:32:25 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/25 22:40:57 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../header.h"

void	ft_lstadd_front(t_philo **lst, t_philo *new)
{
	if (lst && new)
	{
		if (*lst && new)
		{
			new ->prev = *lst;
			(*lst)-> next = new;
		}
	(*lst) = new;
	}
}
