/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 18:15:49 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/02/10 19:28:44 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include "../../libft/libft.h"

typedef struct s_philo
{
	int				fork;
	int				sleep;
	int				think;
	struct s_philo	*next;
}	t_philo;

void	ft_isnumber(char *number);
void	main_parsing(int n, char **v);
void	ft_check_args(int n, char **v);

#endif