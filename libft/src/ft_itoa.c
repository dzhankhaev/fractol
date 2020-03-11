/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 18:05:30 by abeulah           #+#    #+#             */
/*   Updated: 2020/02/25 14:10:29 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_enter(int n, char *s, int i, int f)
{
	int		j;

	if (n == 0)
	{
		s[0] = n + '0';
		s[1] = '\0';
		return ;
	}
	j = ft_count2(n);
	if (i == 2)
	{
		s[j + 1] = '\0';
		s[0] = '-';
	}
	else
	{
		s[j--] = '\0';
	}
	while (n)
	{
		s[j] = (n % 10) + f + '0';
		f = 0;
		j--;
		n /= 10;
	}
}

char		*ft_itoa(int n)
{
	char	*s;
	int		f[2];

	f[0] = 1;
	f[1] = 0;
	if (n < 0)
	{
		if (n == -2147483648)
		{
			n += 1;
			f[1] = 1;
		}
		n *= -1;
		f[0] = 2;
	}
	s = (char *)malloc(sizeof(char) * (ft_count2(n) + f[0]));
	if (s)
		ft_enter(n, s, f[0], f[1]);
	else
		return (0);
	return (s);
}
