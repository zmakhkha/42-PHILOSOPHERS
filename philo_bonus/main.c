/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:18:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/09 14:47:57 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

void	ft_free(t_philo *lst)
{
	int		i;
	t_philo	*tmp;

	i = -1;
	while (++i < lst->d->n_philo)
	{
		tmp = lst;
		lst = lst->prev;
		free(lst);
	}
}

void	ft_wait(t_philo *lst)
{
	int		i;
	int		j;
	int		status;

	i = -1;
	while (++i < lst->d->n_philo)
	{
		lst->d->phil[i] = waitpid(-1, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 10)
		{
			j = -1;
			while (++j < i)
				kill(lst->d->phil[j], SIGKILL);
			while (++j < i)
				kill(lst->d->phil[j], SIGKILL);
			return ;
		}
		if (!lst->d->phil[i])
			lst = lst->prev;
		else
		{
			kill(lst->p_id, SIGKILL);
			lst = lst->prev;
		}
	}
}

// void	s(void)
// {
// 	system(" leaks philo_bonus");
// }

int	main(int n, char **v)
{
	t_data	*shared;
	t_philo	*lst;
	int		i;

	shared = NULL;
	shared = ft_main_parsing(n, v);
	ft_init_philo(&lst, shared);
	i = -1;
	shared->s_t = ft_stime();
	while (++i < shared->n_philo)
	{
		shared->phil[i] = fork();
		if (shared->phil[i] < 0)
			ft_exit("Fork Error\n", 1);
		if (shared->phil[i] == 0)
			ft_start(lst);
		else
		{
			lst ->p_id = shared->phil[i];
			lst = lst->prev;
		}
	}
	ft_wait(lst);
	return (0);
}
