/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:31:33 by alecott           #+#    #+#             */
/*   Updated: 2018/05/29 18:13:13 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	ft_PC_label(t_chain *block, char *str)
{
	int		n;

	n = 0;
	while (block->next)
	{
		n = n + block->size;
		if (ft_strequ(block->category, "LABEL") &&
	ft_strequ(str, ft_strndup(block->content, ft_strlen(block->content) - 1)))
			break;
		block = block->next;
	}
	return (n);
}

static int	ft_PC_ins(t_chain *block, t_chain *start)
{
	int		n;
	t_chain *lst;

	n = 0;
	lst = start;
	if (block->index >= 3)
	{
		while (lst->next && (lst->index != block->index - 3))
			lst = lst->next;
	}
	while (lst->next && !ft_strequ(lst->category, "INSTRUCTION"))
		lst = lst->next;
	while (start->next && start->index != lst->index)
	{
		n = n + start->size;
		start = start->next;
	}
	return (n);
}

char		*ft_find_label(t_chain *block, t_chain *start)
{
	int		PCi;
	int		PCl;
	char	*str;

	if (block->arg_type == DIR_CODE)
		str = ft_strsub(block->content, 2, ft_strlen(block->content));
	else
		str = ft_strsub(block->content, 1, ft_strlen(block->content));
	PCi = ft_PC_ins(block, start);
	PCl = ft_PC_label(start, str);
	if (PCi <= PCl)
		return (ft_itoa(PCl - PCi));
	else
		return (ft_itoa((65536 - (PCi - PCl))));
}
