/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 15:00:09 by abeulah           #+#    #+#             */
/*   Updated: 2020/03/11 15:00:11 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define WIDTH		param[0]
#define MAX_ITER	param[1]
#define FR_ID		param[2]
#define COLOR		param[3]
#define SMOOTH		param[4]
#define MIN_RE		c[0]
#define MAX_IM		c[1]
#define F_RE		c[2]
#define F_IM		c[3]
#define K_RE		c[4]
#define K_IM		c[5]

double			iter_count(double *args, int max_iter, int fr_id, int smooth);

static void		color(int **line, double t, int color, int k)
{
	if (color == 1)
	{
		line[0][k + 2] = (int) (9 * (1 - t) * t * t * t * 255);
		line[0][k + 1] = (int) (15 * (1 - t) * (1 - t) * t * t * 255);
		line[0][k] = (int) (8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
	else if (color == 2)
	{
		line[0][k + 2] = (int) (9 * (1 - t) * t * t * t * 255);
		line[0][k + 1] = (int) (9 * (1 - t) * t * t * t * 255);
		line[0][k] = (int) (9 * (1 - t) * t * t * t * 255);
	}
	else if (color == 3)
	{
		line[0][k + 2] = (int) (10 * (1 - t) * (1 - t) * t * t * 255);
		line[0][k + 1] = (int) (8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
		line[0][k] = (int) (9 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	}
}

__kernel void	calc_pix(__global int *param, __global double *c,
						  __global int *line)
{
	int		gid;
	int		x;
	int		y;
	double	t;
	double	args[4];

	gid = get_global_id(0);
	y = gid / WIDTH;
	x = gid % WIDTH;
	args[0] = K_RE;
	args[1] = K_IM;
	args[2] = MAX_IM - y * F_IM;
	args[3] = MIN_RE + x * F_RE;
	t = iter_count(args, MAX_ITER, FR_ID, SMOOTH);
	color(&line, t, COLOR, x * 3 + y * 3 * WIDTH);
}
