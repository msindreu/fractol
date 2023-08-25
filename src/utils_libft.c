/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_libft.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:07:19 by msindreu          #+#    #+#             */
/*   Updated: 2023/08/01 15:11:55 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	s;

	i = 0;
	s = 1;
	nb = 0;
	if (str[i] == '-')
	{
		s = -s;
		i++;
	}
	while (str[i])
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * s);
}

void	ft_putstr(char *str) 
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		write(1, str + i, 1);
		i++;
	}
}

float	ft_unit_atod(char *str)
{
	float	n;
	float		d;

	n = 0;
	d = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			n = -n;
		str++;
	}

	while (*str != '\0')
	{
		if (*str == '.')
			str++;
		n = n + (*str - 48)/d;
		d *= 10;
		str++;
	}
	return (n);
}

int		ft_len(char *str)
{
	int len;

	len = 0;
	while(str[len] != '\0')
	{
		len++;
	}
	return (len);
}

char	*ft_strrchr(char *s, int c)
{
	size_t	i;

	i = ft_len(s);
	while (i && (char)c != s[i])
		i--;
	if ((char)c == s[i])
		return ((char *)s + i);
	return (0);
}
