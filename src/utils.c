/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:07:19 by msindreu          #+#    #+#             */
/*   Updated: 2023/07/31 15:27:14 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

# define ERROR "Error, please enter a valid argument\n"
# define PLEASE "Please, write one of the follow options:\n"
# define JULIA "Julia (x, y)\n"
# define MANDELBROT "Mandelbrot\n"

void	my_mlx_pixel_put(t_data *data, t_point pixel)
{
	char	*dst;

	dst = data->addr + ((pixel.y - 1) * WINDOW_X * 4 + pixel.x * 4);
	*(int*)dst = pixel.color;
}

void	ft_error(void)
{
	ft_putstr(ERROR);
	ft_putstr(PLEASE);
	ft_putstr(JULIA);
	ft_putstr(MANDELBROT);
}

int		ft_check_input(int argc, char **argv) 
{
	if (argc != 2 || (ft_strcmp(argv[1], "Mandelbrot") != 0 && ft_strcmp(argv[1], "Julia") != 0))
	{
		ft_error();
		return (1);
	}
	return (0);
}

t_complex	ft_complex(int x, int y)
{
	t_complex	c;

	c.x = ((float)x*3.0 / 1920.0) - 2.0;
	c.y = ((float)y*2.0 / 1080.0) - 1.0;
	return(c);
}

int		ft_colors(int i)
{
	if (i > 50 && i < 70)
	{
		return (ROSA);
	}

	if (i > 70 && i < 250)
	{
		return (TURQUESA);
	}

	if (i > 250 && i < 500)
	{
		return (BLANCOROTO);
	}

	if (i == 500)
	{
		return (NEGRE);
	}

	return (AZULMARIN);
}

int		ft_check_values(char *str)
{
	int	i;
	
	i = 0;

	if (ft_len(str > 7))
		return (0);

	if(str[0] == '+' || str[0] == '-')
		str++;
	while(str[i] >= '0' && str[i] <= '9')
		i++;
	if(str[i] == '.')
	{
		str++;
		ft_check_values(str);
	}
	return (i);
}

