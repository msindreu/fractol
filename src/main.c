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

	if (ft_check_input(argc, argv) == 1)
	{
		exit(1);
	}
	void *mlx;
	void *mlx_win;
	t_data	img;
	t_point	pixel;
	t_complex c;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_X, WINDOW_Y, "fractol");
	img.img = mlx_new_image(mlx, WINDOW_X, WINDOW_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	pixel.x = 0;
	pixel.y = 0;
	pixel.color= AZULMARIN;
	mlx_hook(mlx_win, 2, 0, ft_keypress, NULL);
	mlx_hook(mlx_win, 17, 0, ft_exit, NULL);
	mlx_hook(mlx_win, 4, 0, ft_mousepress, NULL);


	
	while(pixel.x <= WINDOW_X && pixel.y < WINDOW_Y)
	{
		c = ft_complex(pixel.x, pixel.y);
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
			pixel.color = ft_colors(ft_mandelbrot(c));
		if (ft_strcmp(argv[1], "Julia") == 0)
			pixel.color = ft_colors(ft_julia(c,ft_unit_atod(argv[2]), ft_unit_atod(argv[3])));
		my_mlx_pixel_put(&img, pixel);
		pixel.x++;
		if (pixel.x == WINDOW_X)
		{
			pixel.x= 0;
			pixel.y++;
		}
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	}

