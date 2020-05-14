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

int		ft_strequ(char *s, char *ss)
{
	int		i;

	i = 0;
	while (s[i] == ss[i])
	{
		if (s[i] == '\0' && ss[i] == '\0')
			return (1);
		i++;
	}
	return (0);
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

void	set_new_values(double *a, double *b, double d)
{
	*a += d * 0.05;
	*b += d * 0.05;
}
