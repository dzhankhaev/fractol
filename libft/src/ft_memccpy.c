/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 15:38:11 by abeulah           #+#    #+#             */
/*   Updated: 2020/02/25 14:10:29 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src,
	int c, size_t num)
{
	size_t	i;

	i = 0;
	while (i < num)
	{
		((char *)dest)[i] = ((char *)src)[i];
		if ((char)c == ((char *)dest)[i])
			return ((char *)(dest + i + 1));
		i++;
	}
	return (0);
}
