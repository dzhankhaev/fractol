/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 18:36:51 by abeulah           #+#    #+#             */
/*   Updated: 2020/02/25 14:10:29 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str,
	const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (ft_strlen(to_find) > ft_strlen(str) || ft_strlen(to_find) > n)
		return (0);
	while (str[i] != '\0' && i < n)
	{
		while (str[i] != '\0' && str[i] == to_find[j] && i < n)
		{
			i++;
			j++;
		}
		if (to_find[j] == '\0' || j == n)
			return ((char *)(str + i - j));
		else
		{
			i = i - j + 1;
			j = 0;
		}
	}
	if ((!(*str) && !(*to_find)) || n == 0)
		return ((char *)(str + 0));
	return (0);
}
