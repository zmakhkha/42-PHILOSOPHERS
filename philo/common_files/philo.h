/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:15:49 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/19 19:08:55 by zmakhkha         ###   ########.fr       */
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

# define EAT	0
# define SLEEP	1
# define THINK	2
# define DIE	3
# define FORK	4

typedef struct s_data
{
	int					n_philo;

	unsigned long		s_t;

	unsigned long		t_sleep;
	unsigned long		t_eat;
	unsigned long		t_alive;

	int					n_meat;
	int					dead;

	int					inf;

}	t_data;

typedef struct s_philo
{
	int					id;
	pthread_t			philo;

	unsigned long		l_sleep;
	unsigned long		l_eat;

	pthread_mutex_t		r_fork;
	pthread_mutex_t		pr;

	t_data				*d;

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
void			ft_fill_philo(t_philo **p, t_data *d);
void			ft_ini_lst(t_philo **p, t_data *d);

// ft_utils
int				ft_isdigit(int c);
size_t			ft_strlen(const char *s);
void			ft_print_error(char *str, int status);
void			ft_void(int n, char **v);
unsigned long	ft_stime(int t);
void			ft_usleep(unsigned long a);

// parsing_utils01
int				ft_isnumber(char *number);
int				main_parsing(int n, char **v);
int				ft_check_args(int n, char **v);

void			ft_sleep(t_philo *p);
void			ft_eat(t_philo *p);
void			ft_think(t_philo *p);

// ft_death
void			ft_set_lmeat(t_philo *p);
int				ft_is_alive(t_philo *p);
void			ft_kill_one(t_philo *p);
void			ft_kill_all(t_philo *p);
int				ft_all_dead(t_philo *p);

//ft_utils2

void			ft_print(char *c);
t_data			*ft_fill_it(int n, char **v);
long long		ft_latoi(const char *str);
int				ft_moment(unsigned long s, unsigned long e);
// unsigned long	ft_moment(unsigned long s);
void			ft_ini_shared(t_data **d);
void			ft_shphilo(t_philo **p, t_data *d);
void			ft_ps(t_philo *p, int s);

// ft_putnbr
void			ft_print(char *c);
void			ft_putnbr(int n);
void			ft_putchar(char c);

// main
void			is_dead(t_data *data);

#endif