/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ocp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 11:05:12 by alecott           #+#    #+#             */
/*   Updated: 2018/05/31 11:00:42 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_ocp(t_chain block, int fd)
{
	int		ocp;
	int		sup;
	int		inf;

	ocp = 0;
	sup = 128;
	inf = 64;
	block = *block.next;
	while (ft_strequ(block.category, "ARG"))
	{
		if (block.arg_type == REG_CODE)
			ocp = ocp + inf;
		else if (block.arg_type == DIR_CODE)
			ocp = ocp + sup;
		else if (block.arg_type == IND_CODE)
			ocp = ocp + sup + inf;
		sup = sup / 4;
		inf = inf / 4;
		block = *block.next;
	}
	ft_putchar_fd(ocp & 0xFF, fd);
}
