/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:18:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/07 15:53:53 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

int	main(int n, char **v)
{
	t_data	*shared;
	t_philo	*lst;
	pid_t	id;
	int		i;

	shared = NULL;
	shared = ft_main_parsing(n, v);
	ft_init_philo(&lst, shared);
	i = -1;
	shared->s_t = ft_stime();
	while (++i < shared->n_philo)
	{
		id = fork();
		if (id < 0)
			ft_exit("Fork Error\n", 1);
		if (!id)
			ft_start(lst);
		else
			lst = lst->prev;
	}
}
