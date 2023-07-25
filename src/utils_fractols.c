/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:11:07 by msindreu          #+#    #+#             */
/*   Updated: 2023/07/25 16:36:51 by msindreu         ###   ########.fr       */
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
	/*if (i > 0 && i < 50)
	{
		return (LILA_MITJ);
	}*/

	if (i > 50 && i < 90)
	{
		return (ROSA);
	}

	if (i > 90 && i < 250)
	{
		return (TURQUESA);
	}
	if (i > 250  && i < 500)
	{
		return (BLANCOROTO);
	}
	if (i == 500) 
	{
		return (NEGRE);
	}
	return (AZULMARIN);
}
