/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:18:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/28 23:14:13 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

void	ft_initiate(t_philo *p)
{
	ft_create_forks(p);
	ft_create_philo(p);
}

void	ft_fill_philo(t_philo **p, t_data *d)
{
	t_philo	*l;
	int		i;

	l = *p;
	i = -1;
	while (++i < d->n_philo)
	{
		l -> d = d;
		l = l -> prev;
	}		
}

void	ft_ini_lst(t_philo **p, t_data *d)
{
	t_philo	*l;
	int		i;

	i = -1;
	while (++i < d->n_philo)
		ft_lstadd_back(p, ft_lstnew());
	l = *p;
	ft_enumerate(p);
	ft_circulare(p);
	ft_fill_philo(p, d);
}

int	main(int n, char **v)
{
	t_data	*shared;
	t_philo	*lst;

	lst = NULL;
	int		i;

	shared = NULL;
	shared = ft_parse_it(n, v);
	if (!shared)
		ft_exit("Allocation Problem !!", 1);
	ft_ini_lst(&lst, shared);
	ft_initiate(lst);
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
