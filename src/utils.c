/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 16:07:19 by msindreu          #+#    #+#             */
/*   Updated: 2023/06/30 18:22:15 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/defines.h"

void	my_mlx_pixel_put(t_data *data, t_point pixel)
{
	char	*dst;

	dst = data->addr + ((pixel.y - 1) * WINDOW_X * 4 + pixel.x * 4);
	*(int*)dst = pixel.color;
}

