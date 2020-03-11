/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:39:16 by abeulah           #+#    #+#             */
/*   Updated: 2020/02/25 14:10:29 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count(char const *s, char c)
{
	int		i;
	int		flag;
	int		count;

	i = 0;
	flag = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	if (s[i] != '\0')
	{
		count = 1;
		while (s[i] != '\0')
		{
			if (s[i] != c && flag)
				count++;
			else if (s[i] == c)
				flag = 1;
			if (s[i] != c)
				flag = 0;
			i++;
		}
		return (count);
	}
	return (0);
}
