/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:28:10 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/25 22:40:27 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../../header.h"

t_philo	*ft_lstnew(void)
{
	t_philo	*new;

	new = (t_philo *) malloc(sizeof(t_philo));
	if (!new)
		return (NULL);
	new -> next = NULL;
	new -> prev = NULL;
	return (new);
}
