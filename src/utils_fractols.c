/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:11:07 by msindreu          #+#    #+#             */
/*   Updated: 2023/07/26 15:40:04 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

int		ft_mandelbrot(t_complex c) 
{
	t_complex z;
	int i;
	double z2x;
	double z2y;
	double x_new;

	i = 0;
	z.x = c.x;
	z.y = c.y;

	while (i < 500 && (z.x*z.x + z.y*z.y) <= 4)
	{
		z2x = z.x*z.x;
		z2y = z.y*z.y;
		x_new = z2x - z2y + c.x;
		z.y = 2*z.x*z.y + c.y;
		z.x = x_new;
		i++;
	}
	return (i);
}

int	ft_julia(t_complex c, double x, double y)
{
	t_complex z;
	int i;
	double z2x;
	double z2y;

	i = 0;
	z.x = c.x;
	z.y = c.y;

	while (i < 500 && (z2x + z2y) <= 4)
	{
		z2x = z.x*z.x;
		z2y = z.y*z.y;
		z.x = z2x + x;
		z.y = z2y + y;
		i++;
	}

	return (i);
}
