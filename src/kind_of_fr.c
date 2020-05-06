/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kind_of_fr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 09:00:10 by abeulah           #+#    #+#             */
/*   Updated: 2020/03/15 09:00:13 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	mandelbrot(t_point c, t_point z, int max_iter)
{
	int		iter;

	iter = 0;
	while (z.re * z.re + z.im * z.im <= 4 && iter < max_iter)
	{
		z = create_cmplx(z.re * z.re - z.im * z.im + c.re,
				2.0 * z.re * z.im + c.im);
		iter++;
	}
	return ((double)iter / (double)max_iter);
}
