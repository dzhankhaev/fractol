/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:00:09 by abeulah           #+#    #+#             */
/*   Updated: 2020/03/11 15:00:11 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include <math.h>
# include "../libft/src/libft.h"
# include "../minilibx_macos/mlx.h"

typedef struct		s_point
{
	double			re;
	double			im;
}					t_point;

typedef struct		s_fr
{
	int				width;
	int				height;
	int				bpp;
	int				size;
	int				endian;
	void			*mlx;
	void			*win;
	void			*img;
	int				zm;
	char			*line;
	t_point			min;
	t_point			max;
	t_point			ms;
}					t_fr;

int					red_cross(void *fr);
int					key_hooks(int key, void *fr);

t_point				create_cmplx(double re, double im);
void				iferror(int f);

double				mandelbrot(t_point c, t_point z, int max_iter);

void				put_pixel(t_fr *fr);

#endif