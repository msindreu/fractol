/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:07:19 by msindreu          #+#    #+#             */
/*   Updated: 2023/07/24 11:45:40 by msindreu         ###   ########.fr       */
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
	if (argc > 1 && argv && ft_strcmp(argv[1], "mandelbrot") != 0)
	{
		ft_error();
		return (1);
	}
	return (0);
}
