/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:09:07 by alecott           #+#    #+#             */
/*   Updated: 2018/05/29 12:16:51 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static int	ft_total_size(t_chain *block)
{
	int		n;

	n = 0;
	while (block->next)
	{
		if (!ft_strequ(block->content, "\n"))
			n = n + block->size;
		block = block->next;
	}
	printf("\nsizetotal=%i\n", n);
	return (n);
}

void		ft_write_cor(int fd, header_t *header, t_chain *block)
{
	int		i;

	ft_putint_bin(COREWAR_EXEC_MAGIC, fd);
	ft_putstr_fd(header->prog_name, fd);
	i = PROG_NAME_LENGTH - ft_strlen(header->prog_name);
	while (i > 0)
	{
		ft_putchar_fd(0 & 0xff, fd);
		i--;
	}
	ft_putint_bin(ft_total_size(block), fd);
	ft_putstr_fd(header->comment, fd);
	i = COMMENT_LENGTH - ft_strlen(header->comment);
	while (i > 0)
	{
		ft_putchar_fd(0 & 0xff, fd);
		i--;
	}
}
