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

static void	destroy(t_fr *fr)
{
	mlx_destroy_window(fr->mlx, fr->win);
	mlx_destroy_image(fr->mlx, fr->img);
	exit(0);
}
#include <stdio.h>
int			key_hooks(int key, void *fr)
{
	printf("%d\n", key);
	if (key == 65307)
		destroy(fr);
	else if (key == 65361)
		put_pixel(fr);
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
