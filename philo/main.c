/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:18:17 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/12 17:51:43 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"common_files/philo.h"

void	ft_void(int n, char **v)
{
	(void)n;
	(void)v;
}

void	ft_ini_lst(t_philo **p, int start)
{
	t_philo	*l;
	int		i;

	i = -1;
	while (++i < 5)
		ft_lstadd_back(p, ft_lstnew());
	l = *p;
	ft_enumerate(p);
	ft_circulare(p);
	ft_initiate(p, start);
}

void	ft_join_t(t_philo *p)
{
	t_philo	*tmp;

	tmp = p;
	while (tmp)
	{
		pthread_join((tmp->philo), NULL);
		tmp = tmp -> prev;
	}
}

int	main(int n, char **v)
{
	t_philo			*tmp;
	t_philo			*lst;
	unsigned long	i;
	unsigned long	t;
	unsigned long	start;

	//main_parsing(n, v);
	ft_void(n, v);
	lst = NULL;
	start = ft_get_start_time(U_S);
	ft_ini_lst(&lst, start);
	tmp = lst;
	i = -1;
	while (++i < 5)
	{
		t = pthread_create(&(lst ->philo), NULL, ft_begin, (void *)(lst));
		if (t)
			return (1);
		lst = lst -> prev;
	}
	ft_join_t(tmp);
	return (0);
}
