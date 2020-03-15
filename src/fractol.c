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
	if (!(fr->mlx = mlx_init()))
		iferror(1);
	if (!(fr->win = mlx_new_window(fr->mlx, fr->width, fr->height, "fractol")))
		iferror(1);
	if (!(fr->img = mlx_new_image(fr->mlx, fr->width, fr->height)))
		iferror(1);
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

	fr.width = 1080;
	fr.height = 1080;
	init(&fr);
	mlx_hook(fr.win, 17, 0, red_cross, (void *)&fr);
	mlx_key_hook(fr.win, key_hooks, (void *)&fr);
	mlx_loop(fr.mlx);
	return (0);
}