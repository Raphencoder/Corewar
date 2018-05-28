/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_cor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 15:09:07 by alecott           #+#    #+#             */
/*   Updated: 2018/05/28 18:04:45 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_write_cor(int fd, header_t *header)
{
	int		i;

	ft_putint_bin(COREWAR_EXEC_MAGIC, fd);
	ft_putstr_fd(header->prog_name, fd);
	i = PROG_NAME_LENGTH - (ft_strlen(header->prog_name) + 4);
	while (i >= 0)
	{
		ft_putchar_fd(0 & 0xff, fd);
		i--;
	}
	ft_putstr_fd(header->comment, fd);
	i = COMMENT_LENGTH - ft_strlen(header->comment);
	while (i > 0)
	{
		ft_putchar_fd(0 & 0xff, fd);
		i--;
	}
}
