/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 14:31:33 by alecott           #+#    #+#             */
/*   Updated: 2018/06/04 13:30:13 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	ft_pc_label(t_chain block, char *str)
{
	int		n;
	char	*tmp;

	n = 0;
	tmp = NULL;
	while (block.next)
	{
		if (tmp)
			ft_strdel(&tmp);
		n = n + block.size;
		if (ft_strequ(block.category, "LABEL") &&
ft_strequ(str, tmp = ft_strndup(block.content, ft_strlen(block.content) - 1)))
			break ;
		block = *block.next;
	}
	if (tmp)
		ft_strdel(&tmp);
	return (n);
}

static int	ft_pc_ins(t_chain block, t_chain start)
{
	int		n;
	t_chain *lst;

	n = 0;
	lst = &start;
	if (block.index > 3)
	{
		while (lst->next && (lst->index != block.index - 3))
			lst = lst->next;
	}
	while (lst->next && !ft_strequ(lst->category, "INSTRUCTION"))
		lst = lst->next;
	while (start.next && start.index != lst->index)
	{
		n = n + start.size;
		start = *start.next;
	}
	return (n);
}

char		*ft_find_label(t_chain block, t_chain start)
{
	int		pci;
	int		pcl;
	char	*str;

	str = NULL;
	if (block.arg_type == DIR_CODE)
		str = ft_strsub(block.content, 2, ft_strlen(block.content));
	else
		str = ft_strsub(block.content, 1, ft_strlen(block.content));
	pci = ft_pc_ins(block, start);
	pcl = ft_pc_label(start, str);
	ft_strdel(&str);
	if (pci <= pcl)
		return (ft_itoa(pcl - pci));
	else
		return (ft_itoa((65536 - (pci - pcl))));
}
