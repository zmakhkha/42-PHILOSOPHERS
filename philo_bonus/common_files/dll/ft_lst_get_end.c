/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_get_end.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:30:30 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/09 08:42:17 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../philo_bonus.h"

t_philo	*ft_lst_get_end(t_philo *list)
{
	t_philo	*tmp;

	tmp = NULL;
	if (list)
	{
		if (!list -> prev)
			return (list);
		tmp = list;
		while (list -> prev)
		{
			tmp = list;
			list = list ->prev;
		}
		return (tmp -> prev);
	}
	return (NULL);
}
