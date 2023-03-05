/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:15:49 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/05 18:48:56 by zmakhkha         ###   ########.fr       */
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

// Habits

# define FORK	0
# define EAT	1
# define SLEEP	2
# define THINK	3
# define DIE	4

// Shared Data Struct

typedef struct s_data
{
	int					n_philo;

	pthread_mutex_t		pr;

	unsigned long		s_t;

	unsigned long		t_sleep;
	unsigned long		t_eat;
	unsigned long		t_alive;

	int					n_meat;
	int					t_meat;
	int					dead;

	int					inf;

}	t_data;

// Philosopher Struct

typedef struct s_philo
{
	int					id;
	pthread_t			philo;

	unsigned long		l_sleep;
	unsigned long		l_eat;

	pthread_mutex_t		r_fork;

	t_data				*d;

	struct s_philo		*next;
	struct s_philo		*prev;
}	t_philo;

// philo list utils common_files/dll
void				ft_lstadd_back(t_philo **lst, t_philo *new);
void				ft_lstadd_front(t_philo **lst, t_philo *new);
t_philo				*ft_lst_get_end(t_philo *list);
t_philo				*ft_lstnew(void);
void				ft_enumerate(t_philo **p);
void				ft_circulare(t_philo **p);

// philo/parsing/
int					ft_isnumber(char *number);
int					ft_check_args(int n, char **v);
int					main_parsing(int n, char **v);

//  ft_habbits
void				*ft_begin(void *p);
void				ft_eat(t_philo *p);
void				ft_sleep(t_philo *p);
void				ft_think(t_philo *p);
void				ft_routin(t_philo *p);

// initiate
void				ft_fill_philo(t_philo **p, t_data *d);
void				ft_ini_lst(t_philo **p, t_data *d);

// ft_long_atoi

long long			ft_latoi(const char *str);

// ft_putnbr
void				ft_putchar(char c);
void				ft_print(char *c);
void				ft_putnbr(int n);
void				ft_stat(t_philo *p, unsigned long time, int action);

// ft_utils
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
unsigned long long	ft_stime(void);
void				ft_usleep(unsigned long a);
void				ft_print_error(char *str, int status); // exit

//ft_utils2

t_data				*ft_fill_it(int n, char **v);
int					ft_moment(t_philo *p);
void				ft_shphilo(t_philo **p, t_data *d);
int					ft_is_alive(t_philo *p);

//ft_actions

void				ft_fork(t_philo *p, unsigned long long time);
void				ft_eating(t_philo *p, unsigned long long time);
void				ft_sleeping(t_philo *p, unsigned long long time);
void				ft_thinking(t_philo *p, unsigned long long time);
void				ft_dead(t_philo *p, unsigned long long time);

// main
void				is_dead(t_data *data);

#endif