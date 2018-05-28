/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_OCP.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/28 10:26:58 by alecott           #+#    #+#             */
/*   Updated: 2018/05/28 10:53:57 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_OCP(t_chain *block, int fd)
{
	int		ocp;
	int		sup;
	int		inf;

	ocp = 0;
	sup = 128;
	inf = 64;
	block = block->next;
	while (ft_strequ(block->category, "ARG"))
	{
		if (block->arg_type == REG_CODE)
			ocp = ocp + inf;
		else if (block->arg_type == DIR_CODE)
			ocp = ocp + sup;
		else if (block->arg_type == IND_CODE)
			ocp = ocp + sup + inf;
		sup = sup / 4;
		inf = inf / 4;
		block = block->next;
	}
	ft_putchar_fd(ocp & 0xFF, fd);
}
