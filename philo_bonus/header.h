/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:15:49 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/26 22:02:29 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <semaphore.h>
# include <fcntl.h>

// status
# define SUCC	0
# define ERR	1

// Habits

# define FORK	0
# define EAT	1
# define SLEEP	2
# define THINK	3
# define DIE	4

// Semaphores nominations
# define FORKS	"fork1"

// Shared Data Struct

typedef struct s_data
{
	int					n_philo;

	pthread_mutex_t		pr;
	pthread_mutex_t		m_dead;
	sem_t				*forks;

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

// philo_bonus/common_files/bonus_utils.c
void				ft_exit(char *str, int stat);

// philo_bonus/common_files/ft_long_atoi.c
long long			ft_latoi(const char *str);

// philo_bonus/common_files/ft_putnbr.c
void				ft_putchar(char c);
void				ft_print(char *c);
void				ft_putnbr(int n);

// philo_bonus/common_files/ft_routine.c
void				ft_routine(t_data *shared, int id);

// philo_bonus/common_files/ft_utils.c
int					ft_isdigit(int c);
size_t				ft_strlen(const char *s);
void				ft_print_error(char *str, int status);

// philo_bonus/common_files/ft_time_utils.c
int					t_moment(t_philo *p);
unsigned long long	ft_stime(void);
void				ft_usleep(unsigned long a);
int					ft_is_alive(t_philo *p);

// philo_bonus/common_files/parsing_utils.c
int					ft_isnumber(char *number);
t_data				*ft_parse_it(int n, char **v);
int					ft_valid_args(int n, char **v);

// philo_bonus/common_files/ft_sems.c
void				ft_create_forks(t_data *shared);
void				ft_create_philo(t_data *shared);
void				ft_destroy(t_data *data);

#endif