/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeulah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 16:15:52 by abeulah           #+#    #+#             */
/*   Updated: 2020/02/25 14:10:29 by abeulah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*a;

	if (!(a = (t_list *)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		a->content = 0;
		a->content_size = 0;
	}
	else
	{
		if ((a->content = ft_strdup(content)) == 0)
		{
			free(a);
			return (0);
		}
		a->content_size = content_size;
	}
	a->next = 0;
	return (a);
}
