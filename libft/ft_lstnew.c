/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:49:39 by alecott           #+#    #+#             */
/*   Updated: 2017/12/17 09:23:55 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*elem;

	if ((elem = (t_list *)malloc(sizeof(t_list))) == 0)
		return (NULL);
	if (content == NULL)
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		elem->content = ft_memcpy(ft_memalloc(content_size + 1),
				content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
