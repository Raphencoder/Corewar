/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 12:32:46 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/16 16:25:00 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;

	fresh = NULL;
	if (!lst)
		return (NULL);
	if ((fresh = (f(ft_lstnew(lst->content, lst->content_size)))))
		fresh->next = ft_lstmap(lst->next, f);
	return (fresh);
}
