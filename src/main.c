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

	mlx = mlx_init();	mlx_win = mlx_new_window(mlx, WINDOW_X, WINDOW_Y, "fractol");
	img.img = mlx_new_image(mlx, WINDOW_X, WINDOW_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	pixel.x = 0;
	pixel.y = 0;
	pixel.color= AZULMARIN;
	
	
	//tres lines de colors

	/*while (i < img.line_length) {
	my_mlx_pixel_put(&img, i, 1080/4, 0x003355FF);
	my_mlx_pixel_put(&img, i, 1080/2, 0X00FF1122);
	my_mlx_pixel_put(&img, i, 1080/2 + 1080/4, 0X0014bebe);
	i++;
	}*/

	//4 pixels grocs a dalt pel bru
	/*while (i < 4){
	my_mlx_pixel_put(&img,i, 5, 0x00e8b025);
	i++;
	}*/

	//quadradet verd bruno
	/*while(i <= 100 && j <= 100) {
	pixel.x = 100+i;
	pixel.y = 100+j;
	pixel.color = AZULMARIN;
	my_mlx_pixel_put(&img, pixel);
	//my_mlx_pixel_put(&img, 100+i, 100+j, AZULMARIN);
	//my_mlx_pixel_put(&img, 100+i, 100+j, AZULMARIN);
	//my_mlx_pixel_put(&img, 100, 100+i, VERD);
	//my_mlx_pixel_put(&img, 200, 100+i, VERD);
	i++;
	if (i == 100) {
		i=0;
		j++;
	}
	}*/

	//pantalla tronja 
	while(pixel.x <= WINDOW_X && pixel.y < WINDOW_Y)
	{
		c = ft_complex(pixel.x, pixel.y);
		if (ft_strcmp(argv[1], "Mandelbrot") == 0)
			pixel.color = ft_colors(ft_mandelbrot(c));
		if (ft_strcmp(argv[1], "Julia") == 0 && (ft_check_values(argv[2]) != 0 && ft_check_values(argv[3]) != 0))
			pixel.color = ft_colors(ft_julia(c, -0.737, 0.285));
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

