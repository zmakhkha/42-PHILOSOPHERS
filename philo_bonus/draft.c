/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 22:42:13 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/26 01:18:23 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"header.h"

// t_data	*ft_ini_data(int n, char **v)
// {
// 	t_data			*data;

// 	data = NULL;
// 	if (!main_parsing(n, v))
// 	{
// 		data = ft_fill_it(n, v);
// 		if (data)
// 		{
// 			data ->dead = 0;
// 			data -> t_meat = data ->n_philo * data -> n_meat;
// 		}
// 	}
// 	return (data);
// }

// static int	ft_main(t_data *shared, t_philo *lst)
// {
// 	int	i;

// 	i = -1;
// 	shared->s_t = ft_stime();
// 	while (++i < shared->n_philo)
// 	{
// 		if (pthread_create(&(lst ->philo), NULL, ft_begin, lst))
// 			return (1);
// 		lst = lst -> prev;
// 	}
// 	while (1)
// 	{
// 		usleep(100);
// 		if (shared->dead || (!shared->t_meat && !shared->inf))
// 			break ;
// 	}
// 	return (0);
// }

// int	main(void)
// {
// 	pid_t	p1, p2, p3;
// 	FILE	*f1, *f2, *f3;

// 	f1 = fopen("/dev/ttys003", "w");
// 	f2 = fopen("/dev/ttys004", "w");
// 	f3 = fopen("/dev/ttys005", "w");
// 	p1 = fork();
// 	p2 = fork();
// 	p3 = fork();
// 	if(!p1)
// 		fprintf(f1, "haaaaana 01\n");
// 	if(!p2)
// 		fprintf(f2, "haaaaana 02\n");
// 	if(!p3)
// 		fprintf(f3, "haaaaana 03\n");
// 	return (0);
// }
