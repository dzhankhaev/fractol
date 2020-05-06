/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 10:50:15 by abeulah           #+#    #+#             */
/*   Updated: 2020/03/15 10:50:17 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	button_4(t_fr *fr, int x, int y)
{
	t_point	xy;

//	xy = create_cmplx(fr->min.re + x * fr->f.re, fr->max.im - y * fr->f.im);

	xy = create_cmplx(
			(double)x / (fr->width / (fr->max.re - fr->min.re))
			+ fr->min.re,
			(double)y / (fr->height / (fr->max.im - fr->min.im))
			* -1 + fr->max.im);

	fr->max.re = xy.re + (fr->max.re - xy.re) * 0.9;
	fr->min.re = xy.re + (fr->min.re - xy.re) * 0.9;
	fr->max.im = xy.im + (fr->max.im - xy.im) * 0.9;
	fr->min.im = xy.im + (fr->min.im - xy.im) * 0.9;
	fr->f = create_cmplx((fr->max.re - fr->min.re) / (fr->width - 1),
						 (fr->max.im - fr->min.im) / (fr->height - 1));

	put_pixel(fr);
}

int			mouse_hooks(int button, int x, int y, void *fr)
{
	if (button == 4)
		button_4(fr, x, y);
//	else if (button == 5)
//		button_5(fdf);
	return (0);
}