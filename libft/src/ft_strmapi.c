/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 18:58:25 by abeulah           #+#    #+#             */
/*   Updated: 2020/02/25 14:10:29 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s,
	char (*f)(unsigned int, char))
{
	unsigned int		i;
	char				*ss;

	if (s && f)
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		ss = (char *)malloc(sizeof(char) * (i + 1));
		if (!ss)
			return (0);
		i = 0;
		while (s[i] != '\0')
		{
			ss[i] = f(i, s[i]);
			i++;
		}
		ss[i] = '\0';
		return (ss);
	}
	return (0);
}
