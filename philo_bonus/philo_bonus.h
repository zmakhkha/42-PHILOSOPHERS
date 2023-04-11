/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:15:49 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/04/11 16:19:47 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

// includeds
# include <semaphore.h>
# include <stdlib.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>

// Status
# define SUCC	0
# define ERR	1

// Semaphores nominations
# define FORKS	"forks"
# define PRINT	"print"
# define MEALS	"meals"

// Shared Data Struct
typedef struct s_data
{
	int					n_philo;

	sem_t				*pr;
	sem_t				*m_dead;
	sem_t				*forks;
	sem_t				*meals;
	pid_t				*phil;

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
	pid_t				p_id;
	pthread_t			philo;

	unsigned long		l_sleep;
	unsigned long		l_eat;

	t_data				*d;

	struct s_philo		*next;
	struct s_philo		*prev;
}	t_philo;

// Lst utils
void				ft_lstadd_back(t_philo **lst, t_philo *new);
void				ft_lstadd_front(t_philo **lst, t_philo *new);
t_philo				*ft_lst_get_end(t_philo *list);
t_philo				*ft_lstnew(void);
void				ft_enumerate(t_philo **p);
void				ft_circulare(t_philo **p);

// commons/ft_parsing.c

int					ft_isnumber(char *number);
int					ft_valid_args(int n, char **v);
void				ft_initsem(t_data *data);
t_data				*ft_main_parsing(int n, char **v);

// commons/ft_utils1.c

void				ft_putchar(char c);
void				ft_print(char *c);
void				ft_putnbr(long long n);
size_t				ret_nbr(char *tmp);
long long			ft_latoi(const char *str);

// commons/ft_utils2.c

int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
void				ft_print_error(char *str, int status);
void				ft_exit(char *str, int stat);
void				ft_close(t_data *data);

// commons/ft_time.c

void				ft_usleep(unsigned long a);
unsigned long long	ft_stime(void);
int					ft_is_alive(t_philo *p);
int					ft_moment(t_philo *p);

// commons/ft_habits.c

void				ft_fork(t_philo *p, unsigned long long time);
void				ft_eating(t_philo *p, unsigned long long time);
void				ft_sleeping(t_philo *p, unsigned long long time);
void				ft_thinking(t_philo *p, unsigned long long time);
void				ft_dead(t_philo *p, unsigned long long time);

// commons/ft_simulation.c

void				ft_eat(t_philo *p);
void				ft_routine(t_philo *p);

// commons/ft_philo.c

void				ft_fill_philo(t_philo **p, t_data *d);
void				ft_init_philo(t_philo **p, t_data *d);
void				ft_start(t_philo *a);

#endif