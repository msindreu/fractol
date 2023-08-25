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

#ifndef DEFINES_H
# define DEFINES_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

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

typedef struct	s_complex {
	double	x;
	double	y;
}                t_complex;


void		my_mlx_pixel_put(t_data *data, t_point pixel);
int			ft_atoi(char *str);
int			ft_strcmp(const char *s1, const char *s2);
void		ft_putstr(char *str);
void		ft_error(void);
void		my_mlx_pixel_put(t_data *data, t_point pixel);
int			ft_check_input(int argc, char **argv);
t_complex	ft_complex(int x, int y);
int			ft_mandelbrot(t_complex c);
int 		ft_julia(t_complex c, float x, float y);
int			ft_colors(int i);
float		ft_unit_atod(char *str);
char		*ft_strchr(const char *s, int c);
int			ft_len(char *str);
int			ft_check_values(char *str);
int	ft_keypress(int key,void *param);

# define TURQUESA 	0X60FAD2
# define LILA_CLAR	0XCD74FC
# define LILA_MITJ	0XA236DC
# define LILA_FOSC	0X7103AC
# define ROSA		0XFC86C8
# define VERD		0X8FD19D
# define AZULCIELO	0X88CCF2
# define AZULMARIN	0X07093B//0X002F68  //00X5760EE
# define CORAL		0XFA535D
# define NARANJA	0XFE834D
# define BLANCOROTO	0XF2F2F2
# define NEGRE		0X000000


#endif
