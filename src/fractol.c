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
	fr->width = 1920;
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
	fr->max.im = (-1 * fr->min.im + fr->max.im) / 2;
}

void		cross(t_fr *fr)
{
	char	*temp;
	t_point	c;
	int x, y;
	y = 0;
	while (y < fr->height)
	{
		c.im = fr->max.im - y * fr->ms.im;
		x = 0;
		while (x < fr->width)
		{
			c.re = fr->min.re + x * fr->ms.re;
			if ((c.im < 0.003 && c.im > -0.003) || (c.re <= 0.002 && c.re >= -0.002))
			{
				temp = (char *)(fr->line + (y * 4 * fr->width));
				temp[x * 4] = (char)0;
				temp[x * 4 + 1] = (char)0;
				temp[x * 4 + 2] = (char)255;
			}
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
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

	init(&fr);
	y = 0;
	while (y < fr.height)
	{
		c.im = fr.max.im - y * fr.ms.im;
		x = 0;
		while (x < fr.width)
		{
			c.re = fr.min.re + x * fr.ms.re;
			z = create_cmplx(c.re, c.im);
			iter = 0;
			while ((z.re * z.re + z.im + z.im) <= 4 && iter < 50)
			{
				z = create_cmplx(z.re * z.re - z.im * z.im + c.re,
						2.0 * z.re * z.im + c.im);
				iter++;
			}
			if (iter == 50)
			{
				temp = (char *)(fr.line + (y * 4 * fr.width));
				temp[x * 4] = (char)255;
				temp[x * 4 + 1] = (char)255;
				temp[x * 4 + 2] = (char)255;
			}
			x++;
		}
		y++;
	}

	mlx_put_image_to_window(fr.mlx, fr.win, fr.img, 0, 0);

//	cross(&fr);

	mlx_hook(fr.win, 17, 0, red_cross, (void *)&fr);
	mlx_key_hook(fr.win, key_hooks, (void *)&fr);
	mlx_loop(fr.mlx);
	return (0);
}