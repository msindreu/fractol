/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:27:46 by msindreu          #+#    #+#             */
/*   Updated: 2023/06/30 13:29:49 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/defines.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	              t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void *mlx;
	//void *mlx_wind;
	void *mlx_win;
	t_data	img;
	float	i;
	float	j;

	mlx = mlx_init();
	i = 0;
	j = 0;
	//mlx_wind = mlx_new_window(mlx, 1920, 1080, "Fractol");
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Fracttititittititiititititit");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	
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
	my_mlx_pixel_put(&img, 100+i, 100+j, AZULMARIN);
	my_mlx_pixel_put(&img, 100+i, 100+j, AZULMARIN);
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
