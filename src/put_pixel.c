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

static void	display_pix(t_fr *fr)
{
	int		i;
	int		y;
	int		x;
	char	*temp;

	i = 0;
	y = 0;
	while (y < fr->height)
	{
		temp = (char *) (fr->line + (y * 4 * fr->width));
		x = 0;
		while (x < fr->width * 4)
		{
			temp[x] = (char)fr->opcl.mem_tl[i];
			temp[x + 1] = (char)fr->opcl.mem_tl[i + 1];
			temp[x + 2] = (char)fr->opcl.mem_tl[i + 2];
			i += 3;
			x += 4;
		}
		y++;
	}
	mlx_put_image_to_window(fr->mlx, fr->win, fr->img, 0, 0);
}

void		put_pixel(t_fr *fr)
{
	t_opcl	*opcl;
	cl_int	ret;
	size_t	global_work_size[1];

	opcl = &fr->opcl;
	global_work_size[0] = fr->width * fr->height;
	init_arg_1(fr);
	init_arg_2(fr);
	init_arg_3(fr);
	ret = clEnqueueNDRangeKernel(opcl->command_queue, opcl->kernel, 1,
			NULL, global_work_size, NULL, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		iferror("ERROR put_pixel.c put_pixel clEnqueueNDRangeKernel\n");
	ret = clEnqueueReadBuffer(opcl->command_queue,
			opcl->memobj_tl, CL_TRUE, 0, opcl->memlenth_tl* sizeof(cl_int),
			opcl->mem_tl, 0, NULL, NULL);
	if (ret != CL_SUCCESS)
		iferror("ERROR put_pixel.c put_pixel clEnqueueReadBuffer\n");
//	clear_win(fr);
	display_pix(fr);
	free(opcl->mem_tl);
	free(opcl->mem_w_mi);
	free(opcl->mem_c);
}