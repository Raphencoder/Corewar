/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:05:05 by alecott           #+#    #+#             */
/*   Updated: 2018/05/23 14:17:21 by alecott          ###   ########.fr       */
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

	start = block;
	str = ft_strndup(str, ft_strlen(str) - 2);
	str = ft_strjoin(str, ".cor");
	fd = open(str, O_WRONLY | O_CREAT, S_IROTH | S_IWUSR | S_IRUSR | S_IRGRP);
	if (fd < 0)
		return;
//	ft_write_in_cor(fd, block, start);
	ft_putstr("Writing output program to ");
	ft_putstr(str);
}
