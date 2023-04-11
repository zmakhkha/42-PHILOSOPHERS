/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:18:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/11 17:21:13 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

void	ft_free(t_philo *lst)
{
	int		i;
	int		n;
	t_philo	*tmp;

	n = lst->d->n_philo;
	free(lst->d->phil);
	free(lst->d);
	i = -1;
	while (lst && ++i < n)
	{
		tmp = lst->prev;
		free(lst);
		lst = tmp;
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
		ft_usleep(200);
		lst->d->phil[i] = waitpid(0, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == 10)
		{
			j = -1;
			while (++j < i)
				kill(lst->d->phil[j], SIGKILL);
			while (++j < lst->d->n_philo)
				kill(lst->d->phil[j], SIGKILL);
			return ;
		}
		if (lst->d->phil[i])
			kill(lst->d->phil[i], SIGKILL);
		lst = lst->prev;
	}
}

void	ft_finish(t_philo *lst)
{
	ft_close(lst->d);
	ft_wait(lst);
	ft_free(lst);
}

int	_main(int n, char **v)
{
	t_data	*shared;
	t_philo	*lst;
	int		i;

	shared = NULL;
	lst = NULL;
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
			lst = lst->prev;
	}
	ft_finish(lst);
	return (0);
}

int	main(int n, char **v)
{
	_main(n, v);
}
