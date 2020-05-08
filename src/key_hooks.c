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

static void	destroy(t_fr *fr)
{
	mlx_destroy_window(fr->mlx, fr->win);
	mlx_destroy_image(fr->mlx, fr->img);
	exit(0);
}

static void	button_move(int key, t_fr *fr)
{
	t_point	d;

	d = create_cmplx(fabs(fr->max.re - fr->min.re),
			fabs(fr->max.im - fr->min.im));
	if (key == LEFT)
	{
		fr->min.re -= d.re * 0.05;
		fr->max.re -= d.re * 0.05;
	}
	else if (key == RIGHT)
	{
		fr->min.re += d.re * 0.05;
		fr->max.re += d.re * 0.05;
	}
	else if (key == UP)
	{
		fr->min.im += d.im * 0.05;
		fr->max.im += d.im * 0.05;
	}
	else if (key == DOWN)
	{
		fr->min.im -= d.im * 0.05;
		fr->max.im -= d.im * 0.05;
	}
	put_pixel(fr);
}

int			key_hooks(int key, void *fr_temp)
{
	t_fr	*fr;

	fr = (t_fr *)fr_temp;
	printf("%d\n", key);
	if (key == 65307)
		destroy(fr);
	else if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		button_move(key, fr);
	else if (key == 124)
		clear_win(fr);
//	else if (key == 125)
//		put_pixel(fr);
	return (0);
}

int			red_cross(void *fr)
{
	fr = 0;
	exit(0);
}
