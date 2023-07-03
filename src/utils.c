/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:07:19 by msindreu          #+#    #+#             */
/*   Updated: 2023/06/30 18:22:15 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

# define ERROR "Error, please neter a valid argument\n"
# define PLEASE "Please, write one of the follow options:\n"
# define JULIA "Julia (x, y)\n"
# define MANDELBROT "Mandelbrot\n"

void	my_mlx_pixel_put(t_data *data, t_point pixel)
{
	char	*dst;

	dst = data->addr + ((pixel.y - 1) * WINDOW_X * 4 + pixel.x * 4);
	*(int*)dst = pixel.color;
}

void	ft_putstr(char *str) 
{
	int i;

	i = 0;
	while(str[i] != '\0') 
	{
		write(2, str + i, 1);
		i++;
	}
}

void	ft_error(void)
{
	ft_putstr(ERROR);
	ft_putstr(PLEASE);
	ft_putstr(JULIA);
	ft_putstr(MANDELBROT);
}

