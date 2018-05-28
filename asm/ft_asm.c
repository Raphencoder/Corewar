/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:05:05 by alecott           #+#    #+#             */
/*   Updated: 2018/05/28 09:40:41 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
/*
void	ft_calcul_ocp(t_chain *block)
{

}

void	ft_write_in_cor(int fd, t_chain *block, t_chain *start)
{
	t_op	*op;

	while (block->next)
	{
		if (ft_strequ(block->category, "INSTRUCTION"))
		{
			op = ft_search_op(block->content);
			ft_putstr(ft_itoa_base(op->opcode, 16));
			if (op->ocp != 0)
				ft_calcul_ocp(block);
		}
		else if (ft_strequ(block->category, "PARAM"))
		else if (ft_strequ(block->category, "LABEL"))
		else if (ft_strequ(block->category, "ENDL"))
		block = block->next;
	}
	block = start;
}
*/

void	ft_asm(char *str, t_chain *block)
{
	int		fd;
	t_chain	*start;

	block = ft_arg_type(block);
	start = block;
	str = ft_strndup(str, ft_strlen(str) - 2);
	str = ft_strjoin(str, ".cor");
	fd = open(str, O_WRONLY | O_CREAT, S_IROTH | S_IWUSR | S_IRUSR | S_IRGRP);
	if (fd < 0)
		return;
	while (block->next)
	{
		ft_putchar('|');
		ft_putstr(block->content);
		ft_putchar('|');
		if (!ft_strequ(block->content, "\n"))
		{
			ft_putstr(" => ");
			ft_putstr(block->category);
			if (ft_strequ(block->category, "ARG"))
			{
				ft_putstr(" => ");
				ft_putnbr(block->arg_type);
			}
			ft_putstr(" SIZE=>");
			ft_putnbr(block->size);
			ft_putstr("		");
		}
		block = block->next;
	}
//	ft_write_in_cor(fd, block, start);
	ft_putstr("Writing output program to ");
	ft_putendl(str);
}
