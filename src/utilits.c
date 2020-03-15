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

t_point create_cmplx(double re, double im)
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