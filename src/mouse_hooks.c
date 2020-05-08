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

int			mouse_hooks(int button, int x, int y, void *fr_temp)
{
	t_point	xy;
	double	zoom;
	t_fr	*fr;

	fr = (t_fr *)fr_temp;
	if (button == 4 || button == 5)
	{
		xy = create_cmplx(
				(double) x / (fr->width / (fr->max.re - fr->min.re))
				+ fr->min.re,
				(double) y / (fr->height / (fr->max.im - fr->min.im))
				* -1 + fr->max.im);
		if (button == 4)
			zoom = 0.9;
		else if (button == 5)
			zoom = 1.1;
		fr->max.re = xy.re + (fr->max.re - xy.re) * zoom;
		fr->min.re = xy.re + (fr->min.re - xy.re) * zoom;
		fr->max.im = xy.im + (fr->max.im - xy.im) * zoom;
		fr->min.im = xy.im + (fr->min.im - xy.im) * zoom;
		fr->f = create_cmplx((fr->max.re - fr->min.re) / (fr->width - 1),
							 (fr->max.im - fr->min.im) / (fr->height - 1));
		put_pixel(fr);
	}
	return (0);
}
