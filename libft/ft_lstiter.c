/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:49:06 by alecott           #+#    #+#             */
/*   Updated: 2017/11/14 15:32:16 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list*tmp;

	if (lst == NULL)
		return ;
	tmp = lst;
	while (tmp->next != NULL)
	{
		f(tmp);
		tmp = tmp->next;
	}
	f(tmp);
}
