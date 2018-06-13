/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:12:44 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/17 13:18:10 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*newlist;

	newlist = NULL;
	if (!(newlist = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (content)
	{
		if (!(newlist->content =
					(void*)malloc(sizeof(void) * content_size)))
			return (NULL);
		newlist->content = ft_memcpy(newlist->content, content, content_size);
		newlist->content_size = content_size;
	}
	else
	{
		newlist->content = NULL;
		newlist->content_size = 0;
	}
	newlist->next = NULL;
	return (newlist);
}
