/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:11:07 by msindreu          #+#    #+#             */
/*   Updated: 2023/07/31 13:26:47 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/defines.h"

int	ft_mandelbrot(t_fractal *fractal)
{
	t_complex	z;
	int			i;
	double		z2x;
	double		z2y;
	double		x_new;

	i = 0;
	z.x = fractal->c.x;
	z.y = fractal->c.y;
	while (i < 500 && (z.x * z.x + z.y * z.y) <= 4)
	{
		z2x = z.x * z.x;
		z2y = z.y * z.y;
		x_new = z2x - z2y + fractal->c.x;
		z.y = 2 * z.x * z.y + fractal->c.y;
		z.x = x_new;
		i++;
	}
	return (i);
}

int	ft_julia(t_fractal *fractal)
{
	t_complex	z;
	int			i;
	double		z2x;
	double		z2y;
	double		x_new;

	i = 0;
	z.x = fractal->c.x;
	z.y = fractal->c.y;
	while (i < 500 && (z.x * z.x + z.y * z.y) <= 4)
	{
		z2x = z.x * z.x;
		z2y = z.y * z.y;
		x_new = z2x - z2y + fractal->k.x;
		z.y = 2 * z.x * z.y + fractal->k.y;
		z.x = x_new;
		i++;
	}
	return (i);
}

void	ft_draw(t_fractal	*fractal)
{
	t_point		pixel;
	// t_complex	c;
	
	pixel.x = 0;
	pixel.y = 0;
	pixel.color = AZULMARIN;
while (pixel.x <= WINDOW_X && pixel.y < WINDOW_Y)
	{
		fractal->c = ft_complex(pixel.x, pixel.y, fractal->zoom);
		pixel.color = ft_colors(fractal->ft_fractal(fractal));
		my_mlx_pixel_put(&fractal->img, pixel);
		pixel.x++;
		if (pixel.x == WINDOW_X)
		{
			pixel.x = 0;
			pixel.y++;
		}
	}
	mlx_put_image_to_window(fractal->mlx, fractal->mlx_win, fractal->img.img, 0, 0);
}
