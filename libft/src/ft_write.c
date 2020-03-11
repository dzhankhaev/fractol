/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:40:52 by abeulah           #+#    #+#             */
/*   Updated: 2020/02/25 14:10:29 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_write(char const *s, char **ss, char c)
{
	int		i;
	int		j;

	i = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i] != c && s[i] != '\0')
		{
			(*ss)[j] = s[i];
			j++;
			i++;
			(*ss)[j] = '\0';
			if (s[i] == c || s[i] == '\0')
				ss++;
		}
		if (s[i] != '\0')
			i++;
	}
}