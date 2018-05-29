/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:05:05 by alecott           #+#    #+#             */
/*   Updated: 2018/05/29 18:13:43 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	ft_write_instruction(t_chain *block, int fd)
{
	t_op	*op_tab;

	op_tab = ft_search_op(block->content);
	ft_putchar_fd(op_tab->opcode & 0xff, fd);
	if (op_tab->ocp)
		ft_OCP(block, fd);
}

static void	ft_write_arg(t_chain *block, t_chain *start, int fd)
{
	char	*str;

	str = "0";
	if (block->arg_type == REG_CODE)
		str = ft_strnmdup(block->content, 1, ft_strlen(block->content));
	else if (block->arg_type == DIR_CODE && ft_isdigit(block->content[1])) //if direct + valeur
			str = ft_strnmdup(block->content, 1, ft_strlen(block->content));
	else if (block->arg_type == IND_CODE && ft_isdigit(block->content[0])) //if indirect+ valeur
			str = block->content;
	else if ((block->arg_type == DIR_CODE && block->content[1] == LABEL_CHAR) // direct et indrect label
			|| (block->arg_type == IND_CODE && block->content[0] == LABEL_CHAR))
		str = ft_find_label(block, start);
	if (block->size == 1)
		ft_putchar_fd(ft_atoi(str) & 0xff, fd);
	else if (block->size == 2)
		ft_putshort_bin(ft_atoi(str), fd);
	else if (block->size == 4)
		ft_putint_bin(ft_atoi(str), fd);
	block = start;
}

void		ft_asm(char *str, t_chain *block, header_t *header)
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
	ft_write_cor(fd, header, start);
/*	while (block->next)
	{
		ft_putchar('|');
		ft_putstr(block->content);
		ft_putnbr(block->index);
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
	block = start;*/
	while (block->next)
	{
		if (ft_strequ(block->category, "INSTRUCTION"))
			ft_write_instruction(block, fd);
		else if (ft_strequ(block->category, "ARG"))
			ft_write_arg(block, start, fd);
		block = block->next;
	}
	ft_putstr("Writing output program to ");
	ft_putendl(str);
}
