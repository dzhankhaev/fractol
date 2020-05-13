/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 14:48:17 by abeulah           #+#    #+#             */
/*   Updated: 2020/03/12 14:48:18 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "key_defines.h"

static void		destroy(t_fr *fr)
{
	mlx_destroy_window(fr->mlx, fr->win);
	mlx_destroy_image(fr->mlx, fr->img);
	exit(0);
}

static void		check_borders(t_fr *fr, t_point *oldvalues)
{
	if (fr->min.re < -5 || fr->max.re > 5 ||
	        fr->min.im < -5 || fr->max.im > 5)
	{
		fr->max = oldvalues[0];
		fr->min = oldvalues[1];
	}
}

static void		button_move(int key, t_fr *fr)
{
	t_point	d;
	t_point oldvalues[2];

	oldvalues[0] = create_cmplx(fr->max.re, fr->max.im);
	oldvalues[1] = create_cmplx(fr->min.re, fr->min.im);
	d = create_cmplx(fabs(fr->max.re - fr->min.re),
			fabs(fr->max.im - fr->min.im));
	if (key == LEFT)
		set_new_values(&fr->min.re, &fr->max.re, d.re * -1);
	else if (key == RIGHT)
		set_new_values(&fr->min.re, &fr->max.re, d.re);
	else if (key == DOWN)
		set_new_values(&fr->min.im, &fr->max.im, d.im * -1);
	else if (key == UP)
		set_new_values(&fr->min.im, &fr->max.im, d.im);
	check_borders(fr, oldvalues);
}

static void		change_iter(int key, t_fr *fr)
{
	if (key == MINUS && fr->max_iter > 100)
		fr->max_iter -= 100;
	else if (key == PLUS && fr->max_iter < 400)
		fr->max_iter += 100;
}

static void		change_color(int key, t_fr *fr)
{
	if (key == ONE)
		fr->color = 1;
	else if (key == TWO)
		fr->color = 2;
	else if (key == THREE)
		fr->color = 3;
}

int				key_hooks(int key, void *fr_temp)
{
	t_fr *fr;

	fr = (t_fr *) fr_temp;
	if (key == ESC)
		destroy(fr);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		button_move(key, fr);
	else if (key == MINUS || key == PLUS)
		change_iter(key, fr);
	else if (key == ONE || key == TWO || key == THREE)
		change_color(key, fr);
	else if (key == TAB)
		fr->smooth = (fr->smooth == 1) ? 0 : 1;
	else if (key == SPACE)
		fr->julia_stop = (fr->julia_stop == 1) ? 0 : 1;
	put_pixel(fr);
	return (0);
}
