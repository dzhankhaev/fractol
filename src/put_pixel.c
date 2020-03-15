/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 09:25:03 by abeulah           #+#    #+#             */
/*   Updated: 2020/03/15 09:25:04 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color(double t, t_fr *fr, int x, int y)
{
	char	*temp;
	int		r;
	int 	g;
	int 	b;

	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	b = (int)(8.5 * pow((1 - t), 3) * t * 255);
	temp = (char *)(fr->line + (y * 4 * fr->width));
	temp[x * 4] = (char)b;
	temp[x * 4 + 1] = (char)g;
	temp[x * 4 + 2] = (char)r;
}


void		put_pixel(t_fr *fr)
{
	t_point	c;
	int		y;
	int		x;
	int		max_iter;
	double	temp;

	y = 0;
	max_iter = 50;
	while (y < fr->height)
	{
		c.im = fr->max.im - y * fr->ms.im;
		x = 0;
		while (x < fr->width)
		{
			c.re = fr->min.re + x * fr->ms.re;
			temp = mandelbrot(c, create_cmplx(c.re, c.im), max_iter);
			color(temp, fr, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}