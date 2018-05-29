/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 13:34:51 by alecott           #+#    #+#             */
/*   Updated: 2018/05/29 12:29:30 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	ft_arg_size2(t_chain *block, t_op *op_tab)
{
	if (ft_strequ(block->category, "INSTRUCTION") && op_tab->ocp == 1)
		return (2);
	else
		return (1);
}

t_chain		*ft_arg_size(t_chain *block)
{
	t_chain	*start;
	t_op	*op_tab;
	char	*last_op;

	start = block;
	while (block->next)
	{
		if (ft_strequ(block->category, "INSTRUCTION"))
			last_op = block->content;
		if (block->arg_type == DIR_CODE || block->arg_type == IND_CODE)
		{
			op_tab = ft_search_op(last_op);
			if (op_tab->label_size)
				block->size = 2;
			else
				block->size = 4;
		}
		else if (ft_strequ(block->category, "LABEL"))
			block->size = 0;
		else
			block->size = ft_arg_size2(block, ft_search_op(block->content));
		block = block->next;
	}
	return (start);
}

t_chain		*ft_arg_type(t_chain *block)
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
	return (ft_arg_size(start));
}
