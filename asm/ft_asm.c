/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 10:05:05 by alecott           #+#    #+#             */
/*   Updated: 2018/05/23 12:12:05 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_write_in_cor(int fd, t_chain *block, t_chain *start)
{
	while (block->next)
	{
		ft_putstr_fd(block->content, fd);
		ft_putchar_fd('|', fd);
		ft_putstr_fd(block->category, fd);
		ft_putchar_fd('	', fd);
		block = block->next;
	}
	block = start;
}

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
	ft_write_in_cor(fd, block, start);
	ft_putstr("Writing output program to ");
	ft_putstr(str);
}
