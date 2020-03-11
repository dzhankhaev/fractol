/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 19:16:13 by abeulah           #+#    #+#             */
/*   Updated: 2020/02/25 14:10:29 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count3(const char *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		if (s[i + 1] == '\0')
			return (1);
		i++;
	}
	return (i);
}

static char	*ft_create(int size, const char *s)
{
	int		i;
	int		j;
	char	*ss;

	i = 0;
	j = 0;
	ss = (char *)malloc(sizeof(char) * size);
	if (ss)
	{
		while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
				&& s[i] != '\0')
			i++;
		while (s[i] != '\0' && j < size - 1)
		{
			ss[j] = s[i];
			i++;
			j++;
		}
		ss[j] = '\0';
		return (ss);
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		c;
	int		size;

	j = 0;
	if (s)
	{
		c = ft_count3(s);
		i = c;
		if (c == 1)
			return (ft_create(1, s));
		while (s[j] != '\0')
			j++;
		size = j;
		while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n'
					|| s[j] == '\0') && j > c)
		{
			i++;
			j--;
		}
		return (ft_create(size - i + 2, s));
	}
	return (0);
}
