/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:58:42 by abeulah           #+#    #+#             */
/*   Updated: 2020/03/11 14:58:44 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#include <stdio.h>

static void	init(t_fr *fr)
{
	fr->width = 1080;
	fr->height = 1080;
	fr->mlx = mlx_init();
	fr->win = mlx_new_window(fr->mlx, fr->width, fr->height, "fractol");
	fr->img = mlx_new_image(fr->mlx, fr->width, fr->height);
	fr->bpp = 4;
	fr->size = 4 * fr->width;
	fr->endian = 0;
	fr->line = mlx_get_data_addr(fr->img, &fr->bpp, &fr->size, &fr->endian);
	fr->min = create_cmplx(-2.0, -2.0);
	fr->max.re = 2;
	fr->max.im = fr->min.im + (fr->max.re - fr->min.re)
			* fr->height / fr->width;
	fr->ms = create_cmplx((fr->max.re - fr->min.re) / (fr->width - 1),
			(fr->max.im - fr->min.im) / (fr->height - 1));
}

int			main(void)
{
	t_fr	fr;
	char	*temp;
	t_point	c;
	t_point	z;
	int		y;
	int		x;
	int		iter;
	int		max_iter;
	int	g, b, r;
	double	t;

	init(&fr);
	y = 0;
	max_iter = 50;
	while (y < fr.height)
	{
		c.im = fr.max.im - y * fr.ms.im;
		x = 0;
		while (x < fr.width)
		{
			c.re = fr.min.re + x * fr.ms.re;
			z = create_cmplx(c.re, c.im);
			iter = 0;
			while (pow(z.re, 2) + pow(z.im, 2) <= 4 && iter < max_iter)
			{
				z = create_cmplx(pow(z.re, 2) - pow(z.im, 2) + c.re,
						2.0 * z.re * z.im + c.im);
				iter++;
			}
			t = (double)iter / (double)max_iter;
			r = (int)(9 * (1 - t) * pow(t, 3) * 255);
			g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
			b = (int)(8.5 * pow((1 - t), 3) * t * 255);
			temp = (char *)(fr.line + (y * 4 * fr.width));
			temp[x * 4] = (char)b;
			temp[x * 4 + 1] = (char)g;
			temp[x * 4 + 2] = (char)r;
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(fr.mlx, fr.win, fr.img, 0, 0);

	mlx_hook(fr.win, 17, 0, red_cross, (void *)&fr);
	mlx_key_hook(fr.win, key_hooks, (void *)&fr);
	mlx_loop(fr.mlx);
	return (0);
}