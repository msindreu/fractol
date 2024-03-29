/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:07:19 by msindreu          #+#    #+#             */
/*   Updated: 2023/08/01 15:52:32 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/defines.h"
#include "../inc/keycodes.h"

#define ERROR "Error, please enter a valid argument\n"
#define PLEASE "Please, write one of the follow options:\n"
#define JULIA "Julia (x, y)\n"
#define MANDELBROT "Mandelbrot\n"

void	ft_error(void)
{
	ft_putstr(ERROR);
	ft_putstr(PLEASE);
	ft_putstr(JULIA);
	ft_putstr(MANDELBROT);
}

int	ft_check_input(int argc, char **argv)
{
	if ((argc < 2 || argc > 4) 
		|| (argc == 2 && ft_strcmp(argv[1], "Mandelbrot") != 0) 
		|| (ft_strcmp(argv[1], "Julia") == 0 && argc != 4))
	{
		ft_error();
		return (1);
	}
	if (argc == 4 && (ft_strcmp(argv[1], "Julia") == 0))
	{
		if (ft_check_values(argv[2]) != 3 || ft_check_values(argv[3]) != 3)
		{
			ft_error();
			return (1);
		}
	}
	return (0);
}

t_complex	ft_complex(int x, int y, double zoom)
{
	t_complex	c;

	c.x = (((float)x * 3.0 / 1920.0) - 2.0) / zoom;
	c.y = (((float)y * 2.0 / 1080.0) - 1.0) / zoom;
	return (c);
}

int	ft_colors(int i)
{
	if (i < 15)
		return (AZULMARIN);
	if (i < 30)
		return (TURQUESA);
	if (i < 45)
		return (AZULCIELO);
	if (i < 60)
		return (LILA_CLAR);
	if (i < 75)
		return (BLANCOROTO);
	if (i < 90)
		return (ROSA);
	if (i < 105)
		return (NARANJA);
	if (i < 120)
		return (CORAL);
	if (i < 150)
		return (VERD);
	if (i == 500)
		return (NEGRE);
	return (AZULMARIN);
}

int	ft_check_values(char *str)
{
	int	i;

	i = 0;
	if (ft_len(str) > 7)
	{
		ft_error();
		return (0);
	}
	if (str[0] == '+' || str[0] == '-')
		str++;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '.')
	{
		str = str + 2;
		i = ft_check_values(str);
	}
	return (i);
}
