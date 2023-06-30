/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msindreu <msindreu@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:41:01 by msindreu          #+#    #+#             */
/*   Updated: 2023/06/30 16:40:42 by msindreu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define WINDOW_X 1920
# define WINDOW_Y 1080


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	              t_data;

typedef struct s_point {
	int		x;
	int		y;
	int		color;
}                 t_point;

void	my_mlx_pixel_put(t_data *data, t_point pixel);

# define TURQUESA 	0X60FAD2
# define LILA		0XCD74FC
# define ROSA		0XFC86C8
# define VERD		0X8FD19D
# define AZULCIELO	0X88CCF2
# define AZULMARIN	0X5760EE
# define CORAL		0XFA535D
# define NARANJA	0XFE834D
# define BLACOROTO	0XF2F2F2


#endif
