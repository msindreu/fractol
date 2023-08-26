/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:27:46 by msindreu          #+#    #+#             */
/*   Updated: 2023/08/01 15:52:29 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/defines.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	//t_point		pixel;

	if (ft_check_input(argc, argv) == 1)
		exit(1);
	

	fractal.mlx = mlx_init();
	fractal.mlx_win = mlx_new_window(fractal.mlx, WINDOW_X, WINDOW_Y, "fractol");
	fractal.img.img = mlx_new_image(fractal.mlx, WINDOW_X, WINDOW_Y);
	fractal.img.addr = mlx_get_data_addr(fractal.img.img, &fractal.img.bits_per_pixel, &fractal.img.line_length, &fractal.img.endian);
	fractal.zoom = 1;
	
	if (ft_strcmp(argv[1], "Julia") == 0)
	{
		fractal.k.x = ft_unit_atod(argv[2]);
		fractal.k.y = ft_unit_atod(argv[3]);
		fractal.ft_fractal = ft_julia;
	}
	else
		fractal.ft_fractal = ft_mandelbrot;

	mlx_hook(fractal.mlx_win, 2, 0, ft_keypress, NULL);
	mlx_hook(fractal.mlx_win, 17, 0, ft_exit, NULL);
	mlx_hook(fractal.mlx_win, 4, 0, ft_mousepress, &fractal);
	
	ft_draw(&fractal);
	mlx_loop(fractal.mlx);
}