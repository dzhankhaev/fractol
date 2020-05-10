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

int			red_cross(void *fr)
{
	fr = 0;
	exit(0);
}

static int		check_down(t_fr *fr, t_point xy)
{
	t_point	new_val[2];
	double	zoom;

	zoom = 1.1;
	new_val[0] = create_cmplx(fr->max.re, fr->max.im);
	new_val[1] = create_cmplx(fr->min.re, fr->min.im);
	new_val[0].re = xy.re + (fr->max.re - xy.re) * zoom;
	new_val[1].re = xy.re + (fr->min.re - xy.re) * zoom;
	new_val[0].im = xy.im + (fr->max.im - xy.im) * zoom;
	new_val[1].im = xy.im + (fr->min.im - xy.im) * zoom;
	if (new_val[0].re > 5 || new_val[1].re < -5
		|| new_val[0].im > 5 || new_val[1].im < -5)
		return (1);
	return (0);
}

static double	set_zoom(int button, t_fr *fr, t_point xy)
{
	if (button == 4)
	{
		if (fr->f.re < 1e-17 || fr->f.im < 1e-17)
			return (1);
		return (0.9);
	}
	else
	{
		if (check_down(fr, xy))
			return (1);
		return (1.1);
	}
}

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
		zoom = set_zoom(button, fr, xy);
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
