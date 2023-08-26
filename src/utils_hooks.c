/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:41:01 by msindreu          #+#    #+#             */
/*   Updated: 2023/07/31 15:27:07 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../mlx/mlx.h"
#include "../inc/defines.h"
#include "../inc/keycodes.h"

int	ft_keypress(int key, void *param)
{
	(void)*param;
	if (key == KEY_ESC)
		exit(1);
	return (1);
}

int	ft_exit(void *param)
{
	(void)*param;
	exit(1);
}

int	ft_mousepress(int button, int x, int y, t_fractal *fractal)
{
	(void)x;
	(void)y;
	if (button == 4)
		fractal->zoom /= 0.5;
	if (button == 5)
		fractal->zoom *= 0.5;
	ft_draw(fractal);
	return (0);
}
