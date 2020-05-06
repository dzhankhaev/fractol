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

void	iferror(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		write(1, &s[i++], 1);
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

char	*ft_copy(char *buf, int length)
{
	char	*a;
	int		i;

	a = (char *)malloc(sizeof(char) * (length + 1));
	if (!a)
		return (0);
	i = 0;
	while (i < length)
	{
		a[i] = buf[i];
		i++;
	}
	a[i] = '\0';
	return (a);
}