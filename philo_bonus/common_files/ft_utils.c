/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 10:56:50 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/26 01:34:39 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

int	ft_isdigit(int c)
{
	return ((48 <= c) && (c <= 57));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_print_error(char *str, int status)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit (status);
}
