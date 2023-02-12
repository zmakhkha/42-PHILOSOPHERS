/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:15:49 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/12 18:04:47 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define S		0
# define U_S	1

typedef struct s_philo
{
	int					id;
	pthread_t			philo;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		pr;
	unsigned long		t_sleep;
	unsigned long		l_sleep;
	unsigned long		t_eat;
	unsigned long		l_eat;
	unsigned long		died;
	unsigned long		t_alive;
	unsigned long		start;
	int					t_think;
	struct s_philo		*next;
	struct s_philo		*prev;
}	t_philo;

// philo list utils philo/dll
void			ft_lstadd_back(t_philo **lst, t_philo *new);
void			ft_lstadd_front(t_philo **lst, t_philo *new);
t_philo			*ft_lst_get_end(t_philo *list);
t_philo			*ft_lstnew(void);

// initiate
void			ft_enumerate(t_philo **p);
void			ft_circulare(t_philo **p);
void			*ft_begin(void *p);
void			ft_routin(t_philo *p);
void			ft_initiate(t_philo **p, unsigned long s);

// ft_utils
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
void			ft_print_error(char *str, int status);
void			ft_void(int n, char **v);
unsigned long	ft_get_start_time(int t);
void			ft_usleep(unsigned long a);

// parsing_utils01
void			ft_isnumber(char *number);
void			main_parsing(int n, char **v);
void			ft_check_args(int n, char **v);

void			ft_sleep(t_philo *p);
void			ft_eat(t_philo *p);
void			ft_think(t_philo *p);

// main
#endif