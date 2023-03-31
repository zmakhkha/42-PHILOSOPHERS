/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zmakhkha <zmakhkha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 15:59:48 by zmakhkha          #+#    #+#             */
/*   Updated: 2023/03/28 21:27:30 by zmakhkha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../header.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t len)
{
	size_t		i;
	char		*s;

	s = (char *)src;
	if (len != 0)
	{
		i = 0;
		len --;
		while (src[i] && i < len)
		{
			dst[i] = s[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(s));
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*res;

	len = ft_strlen(s1);
	res = (char *) malloc(len + 1);
	if (!res)
		return (NULL);
	if (s1)
		ft_strlcpy(res, s1, len + 1);
	else
		return (NULL);
	return (res);
}

static	int	get_size(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	n *= -1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*get_limits(int n)
{
	if (n == 2147483647)
		return (ft_strdup("2147483647"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	return (NULL);
}

char	*ft_itoa(int n)
{
	int		i;
	int		j;
	char	*res;

	res = get_limits(n);
	if (res == NULL)
	{
		i = get_size(n);
		res = (char *)malloc((i + 1) * sizeof(char));
		if (!res)
			return (NULL);
		j = i - 1;
		if (n < 0)
		{
			res[0] = '-';
			n = n * -1;
		}
		while (n > 0)
		{
			res[j--] = '0' + (int)n % 10;
			n /= 10;
		}
		res[i] = 0;
	}
	return (res);
}