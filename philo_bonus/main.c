/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:18:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/03 15:51:36 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

//void	ft_initiate(t_philo *p)
//{
	
//}

void	ft_fill_philo(t_philo **p, t_data *d)
{
	t_philo	*l;
	int		i;

	l = *p;
	i = -1;
	while (++i < d->n_philo)
	{
		l -> d = *d;
		l = l -> prev;
	}		
}

void	ft_ini_lst(t_philo **p, t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->n_philo)
		ft_lstadd_back(p, ft_lstnew());
	ft_enumerate(p);
	ft_circulare(p);
	ft_fill_philo(p, d);
}

int	main(int n, char **v)
{
	//t_data	*shared;
	t_data	shared;
	t_philo	*lst;
	int		pid;
	int		i;
	lst = NULL;

	shared = ft_parse_it(n, v);
	ft_ini_lst(&lst, &shared);
	i = -1;
	while (++i < shared.n_philo)
	{
		lst->l_eat = shared.s_t;
		lst->l_sleep = shared.s_t;
		lst = lst->prev;
	}
	i = -1;
	while (++i < shared.n_philo)
	{
		pid = fork();
		if (pid < 0)
			perror("Mochkil fel fork !!\n");
		else if (!pid)
		{
			ft_routine(lst);
		}
		else
			lst = lst->prev;
	}
	while(1)
	{
		ft_usleep(100);
		pid = waitpid(-1, NULL, 0);
		if (pid == -1)
			exit(0);
	}	
}
