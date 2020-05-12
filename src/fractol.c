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

static void	fr_name(t_fr *fr, char *name)
{
	if (ft_strequ("mandelbrot", name))
		fr->fr_name = 0;
	else if (ft_strequ("burning ship", name))
		fr->fr_name = 1;
	else if (ft_strequ("celtic mandelbrot", name))
		fr->fr_name = 2;
	else if (ft_strequ("julia", name))
		fr->fr_name = 3;
	else
		iferror("Invalid arguments!\n");
}

static void	init(t_fr *fr)
{
	fr->width = 1000;
	fr->height = 1000;
	if (!(fr->mlx = mlx_init()))
		iferror("ERROR fractol.c init_mlx mlx_init\n");
	if (!(fr->win = mlx_new_window(fr->mlx, fr->width, fr->height, "fractol")))
		iferror("ERROR fractol.c init_mlx mlx_new_window\n");
	if (!(fr->img = mlx_new_image(fr->mlx, fr->width, fr->height)))
		iferror("ERROR fractol.c init_mlx mlx_new_image\n");
	fr->bpp = 4;
	fr->size = 4 * fr->width;
	fr->endian = 0;
	fr->line = mlx_get_data_addr(fr->img, &fr->bpp, &fr->size, &fr->endian);
	fr->min = create_cmplx(-2.0, -2.0);
	fr->max.re = 2;
	fr->max.im = fr->min.im + (fr->max.re - fr->min.re)
			* fr->height / fr->width;
	fr->f = create_cmplx((fr->max.re - fr->min.re) / (fr->width - 1),
			(fr->max.im - fr->min.im) / (fr->height - 1));
	fr->max_iter = 100;
	fr->julia_k.re = FIRST;
}

int			main(int argc, char **argv)
{
	t_fr	fr;

	if (argc != 2)
		iferror("Invalid arguments!\n");
	init(&fr);
	fr_name(&fr, argv[1]);
	init_opcl(&fr);
	mlx_hook(fr.win, 6, 1L << 6, mousemove_hook, (void *)&fr);
	mlx_key_hook(fr.win, key_hooks, (void *)&fr);
	mlx_mouse_hook(fr.win, mouse_hooks, (void *)&fr);
	mlx_loop(fr.mlx);
	return (0);
}
