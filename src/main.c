/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:27:46 by msindreu          #+#    #+#             */
/*   Updated: 2023/06/30 16:42:43 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/defines.h"
#include "utils.c"

int	main(void)
{
	void *mlx;
	void *mlx_win;
	t_data	img;
	float	i;
	float	j;
	t_point	pixel;

	mlx = mlx_init();
	i = 0;
	j = 0;
	mlx_win = mlx_new_window(mlx, WINDOW_X, WINDOW_Y, "Fracttititittititiititititit");
	img.img = mlx_new_image(mlx, WINDOW_X, WINDOW_Y);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	pixel.x = 100+i;
	pixel.y = 100+j;
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
	while(i <= 100 && j <= 100) {
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
	}

	//diagonal blaveta
/*	while (i < 1920 && j < 1080) {
		my_mlx_pixel_put(&img, i, j, 0X0014bebe);
		i = i + 1 + 1920/1080;
		j = j +1 - 1920/1080;
	}*/


	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);

}
