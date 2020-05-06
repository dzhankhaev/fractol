/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 09:25:03 by abeulah           #+#    #+#             */
/*   Updated: 2020/03/15 09:25:04 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	color(double t, t_fr *fr, int x, int y)
{
	char	*temp;
	int		r;
	int		g;
	int		b;

	r = (int)(9 * (1 - t) * pow(t, 3) * 255);
	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	b = (int)(8.5 * pow((1 - t), 3) * t * 255);
	if (y < fr->height && x < fr->width)
	{
		temp = (char *) (fr->line + (y * 4 * fr->width));
		temp[x * 4] = (char) b;
		temp[x * 4 + 1] = (char) g;
		temp[x * 4 + 2] = (char) r;
	}
}

void		put_pixel(t_fr *fr)
{
	t_opcl	*opcl;
	cl_int	ret;
	size_t	global_work_size[1];

	init_arg_2(fr);
	opcl = &fr->opcl;
	global_work_size[0] = 10; /*количество work-item'ов*/
	ret = clEnqueueNDRangeKernel(opcl->command_queue, opcl->kernel, 1, NULL,
			global_work_size, NULL, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		iferror("ERROR put_pixel.c put_pixel clEnqueueReadBuffer\n");
	ret = clEnqueueReadBuffer(opcl->command_queue, opcl->memobj_min_max_f,
			CL_TRUE, 0,	opcl->memlenth_min_max_f * sizeof(cl_double),
			opcl->mem_min_max_f, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		iferror("ERROR put_pixel.c put_pixel clEnqueueReadBuffer\n");
}

/*
void		put_pixel(t_fr *fr)
{
	t_point	c;
	int		y;
	int		x;
	int		max_iter;
	double	temp;

	clear_win(fr);
	y = 0;
	max_iter = 50;
	while (y < fr->height)
	{
		c.im = fr->max.im - y * fr->f.im;
		x = 0;
		while (x < fr->width)
		{
			c.re = fr->min.re + x * fr->f.re;
			temp = mandelbrot(c, create_cmplx(c.re, c.im), max_iter);
			color(temp, fr, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}
*/