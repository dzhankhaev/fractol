/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:57:07 by abeulah           #+#    #+#             */
/*   Updated: 2020/02/25 14:10:29 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cnt(char const *s, char c, int i)
{
	int		count;

	count = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		count++;
		i++;
	}
	return (++count);
}

static char	**ft_allocate_mem(char const *s, char c, int n, int j)
{
	int		i;
	char	**ss;

	i = 0;
	if (!(ss = (char**)malloc(sizeof(char *) * (n + 1))))
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
		{
			ss[j] = (char*)malloc(sizeof(char) * ft_cnt(s, c, i));
			if (!ss[j])
				return (ft_freetab(ss, j + 1));
			j++;
			i = ft_bl(s, c, i);
		}
		if (s[i] != '\0')
			i++;
	}
	ss[n] = 0;
	return (ss);
}

static char	**ft_nen(void)
{
	char	**s;

	if (!(s = (char **)malloc(sizeof(char *))))
		return (0);
	s[0] = 0;
	return (s);
}

char		**ft_strsplit(char const *s, char c)
{
	int		n;
	char	**ss;

	if (s)
	{
		n = ft_count(s, c);
		if (!n)
			return (ft_nen());
		ss = ft_allocate_mem(s, c, n, 0);
		if (ss)
		{
			ft_write(s, ss, c);
			return (ss);
		}
	}
	return (0);
}
