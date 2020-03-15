/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilits.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 15:32:02 by abeulah           #+#    #+#             */
/*   Updated: 2020/03/12 15:32:03 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_point	create_cmplx(double re, double im)
{
	t_point a;

	a.re = re;
	a.im = im;
	return (a);
}

void	iferror(int f)
{
	if (f == 1)
		ft_putstr("MLX returned NULL!\n");
	exit(0);
}

void	clear_win(t_fr *fr)
{
	int		x;
	int 	y;
	char	*temp;

	y = 0;
	while (y < fr->height)
	{
		x = 0;
		while (x < fr->width)
		{
			temp = (char *) (fr->line + (y * 4 * fr->width));
			temp[x * 4] = (char)0;
			temp[x * 4 + 1] = (char)0;
			temp[x * 4 + 2] = (char)0;
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}