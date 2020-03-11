/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 18:07:09 by abeulah           #+#    #+#             */
/*   Updated: 2020/02/25 14:10:29 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start,
	size_t len)
{
	size_t	i;
	int		j;
	char	*ss;

	i = len + 1;
	if (len > i)
		return (0);
	i = 0;
	j = 0;
	if (s)
	{
		ss = (char *)malloc(sizeof(char) * (len + 1));
		if (!ss)
			return (0);
		i = start;
		while (i < len + start)
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
