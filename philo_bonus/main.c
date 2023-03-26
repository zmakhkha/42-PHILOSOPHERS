/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:18:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/26 01:28:37 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	ft_initiate(t_data *shared)
{
	ft_create_forks(shared);
	ft_create_philo(shared);
}

int	main(int n, char **v)
{
	t_data	*shared;
	int		i;

	shared = NULL;
	shared = ft_parse_it(n, v);
	shared = ft_parse_it(n, v);
	if (!shared)
		ft_exit("Allocation Problem !!", 1);
	ft_initiate(shared);
	// // wait for all the process
	i = -1;
	while (++i < shared->n_philo)
	{
		waitpid(-1, NULL, 0);
	}	
	// Destroy all the semaphores
	ft_destroy(shared);
	free(shared);
}
