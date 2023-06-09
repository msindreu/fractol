/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:27:46 by msindreu          #+#    #+#             */
/*   Updated: 2023/06/09 17:50:47 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../mlx/mlx.h"
#include "../inc/defines.h"

int	main(void)
{
	void *mlx;
	void *mlx_wind;
	void *mlx_wind2;

	mlx = mlx_init();
	mlx_wind = mlx_new_window(mlx, 1920, 1080, "Fractol");
	mlx_wind2 = mlx_new_window(mlx, 900, 500, "Fracttititittititiititititit");
	mlx_loop(mlx);
}
