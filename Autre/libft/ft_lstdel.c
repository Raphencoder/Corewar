/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 20:14:18 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/16 15:33:05 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*unit;
	t_list	*nexts;

	unit = *alst;
	nexts = NULL;
	if (unit->next)
	{
		nexts = unit->next;
		ft_lstdel(&nexts, del);
	}
	ft_lstdelone(&unit, del);
	*alst = NULL;
}
