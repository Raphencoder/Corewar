/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:34:51 by alecott           #+#    #+#             */
/*   Updated: 2018/06/28 12:59:47 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static	char	*ft_last_op(char *last_op, t_chain block)
{
	char *tmp;

	tmp = last_op;
	if (ft_strequ(block.category, "INSTRUCTION"))
	{
		if (last_op)
			ft_strdel(&last_op);
		tmp = ft_strdup(block.content);
	}
	return (tmp);
}

static int		ft_arg_size2(t_chain block, t_op *op_tab)
{
	if (ft_strequ(block.category, "INSTRUCTION") && op_tab->ocp == 1)
		return (2);
	else
		return (1);
}

static void		ft_arg_size(t_chain *block)
{
	t_op	*op_tab;
	char	*last_op;

	last_op = NULL;
	while (block->next)
	{
		last_op = ft_last_op(last_op, *block);
		if (block->arg_type == DIR_CODE || block->arg_type == IND_CODE)
		{
			op_tab = ft_search_op(last_op);
			if (block->arg_type == IND_CODE || op_tab->label_size)
				block->size = 2;
			else
				block->size = 4;
		}
		else if (ft_strequ(block->category, "LABEL") ||
				ft_strequ(block->content, "\n"))
			block->size = 0;
		else
			block->size = ft_arg_size2(*block, ft_search_op(block->content));
		block = block->next;
	}
	ft_strdel(&last_op);
	block->next = 0;
}

void			ft_arg_type(t_chain *block)
{
	t_chain	*start;

	start = block;
	while (block->next)
	{
		if (ft_strequ(block->category, "ARG"))
		{
			if (block->content[0] == 'r')
				block->arg_type = REG_CODE;
			else if (block->content[0] == DIRECT_CHAR)
				block->arg_type = DIR_CODE;
			else
				block->arg_type = IND_CODE;
		}
		block = block->next;
	}
	block->next = 0;
	ft_arg_size(start);
}
