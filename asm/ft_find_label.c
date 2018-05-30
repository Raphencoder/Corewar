/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:31:33 by alecott           #+#    #+#             */
/*   Updated: 2018/05/30 14:20:39 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	ft_pc_label(t_chain *block, char *str)
{
	int		n;

	n = 0;
	while (block->next)
	{
		n = n + block->size;
		if (ft_strequ(block->category, "LABEL") &&
	ft_strequ(str, ft_strndup(block->content, ft_strlen(block->content) - 1)))
			break ;
		block = block->next;
	}
	return (n);
}

static int	ft_pc_ins(t_chain *block, t_chain *start)
{
	int		n;
	t_chain *lst;

	n = 0;
	lst = start;
	if (block->index > 3)
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
	int		pci;
	int		pcl;
	char	*str;

	if (block->arg_type == DIR_CODE)
		str = ft_strsub(block->content, 2, ft_strlen(block->content));
	else
		str = ft_strsub(block->content, 1, ft_strlen(block->content));
	pci = ft_pc_ins(block, start);
	pcl = ft_pc_label(start, str);
	printf("\ncontent= %s pci= %i pcl = %i\n", block->content, pci, pcl);
	if (pci <= pcl)
		return (ft_itoa(pcl - pci));
	else
		return (ft_itoa((65536 - (pci - pcl))));
}
