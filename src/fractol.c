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

void	init(t_fr *fr)
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
}

int		main(void)
{
	t_fr	fr;
	char	*temp;

	init(&fr);

	int x0 = 1;
	int y0 = 2;
	temp = (char *)(fr.line + (y0 * 4 * fr.width));
	temp[x0 * 4] = (char)255;
	temp[x0 * 4 + 1] = (char)255;
	temp[x0 * 4 + 2] = (char)255;

	mlx_put_image_to_window(fr.mlx, fr.win, fr.img, 0, 0);

	mlx_hook(fr.win, 17, 0, red_cross, (void *)&fr);
	mlx_key_hook(fr.win, key_hooks, (void *)&fr);
	mlx_loop(fr.mlx);
	return (0);
}