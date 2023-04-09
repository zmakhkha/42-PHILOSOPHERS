/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:18:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/09 03:20:39 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

void	ft_wait(t_philo *lst)
{
	int		i;
	pid_t	tmp;

	i = -1;
	while (++i < lst->d->n_philo)
	{
		waitpid(-1, &tmp, 0);
		if (!tmp)
			lst = lst->prev;
		else
		{
			kill(lst->p_id, SIGKILL);
			lst = lst->prev;
		}
	}
}

int	main(int n, char **v)
{
	t_data	*shared;
	t_philo	*lst;
	int		i;

	shared = NULL;
	shared = ft_main_parsing(n, v);
	if (!shared)
		ft_exit("parsing khaaawi !! \n", 1);
	ft_init_philo(&lst, shared);
	i = -1;
	shared->s_t = ft_stime();
	while (++i < shared->n_philo)
	{
		shared->phil[i] = fork();
		if (shared->phil[i] < 0)
			ft_exit("Fork Error\n", 1);
		if (shared->phil[i] == 0)
		{
			lst->p_id = getpid();
			ft_start(lst);
		}
		else
		{
			lst ->p_id = shared->phil[i];
			lst = lst->prev;
		}
	}
	ft_wait(lst);
}
