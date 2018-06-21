/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 11:12:03 by abouvero          #+#    #+#             */
/*   Updated: 2018/06/13 16:44:33 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		known_opt(char *opt)
{
	if (!ft_strcmp(opt, "-n") || !ft_strcmp(opt, "-dump"))
		return (1);
	if (!ft_strcmp(opt, "-v"))
		return (1);
	return (0);
}

int		activate_visu(t_vm *vm, int *i, int ac)
{
	vm->visu = 1;
	if (*i + 1 == ac)
	{
		if (!vm->champ)
			ft_dprintf(2, "No champ loaded\n");
		return (0);
	}
	*i += 1;
	return (1);
}

int		check_inputs(void)
{
	int		err;

	err = 1;
	if (MAX_PLAYERS < 1 || MEM_SIZE < 1 || CHAMP_MAX_SIZE < 1)
		err = 0;
	if (CYCLE_TO_DIE < 1 || CYCLE_DELTA < 1 || NBR_LIVE < 1
											|| MAX_CHECKS < 1)
		err = 0;
	if (PROG_NAME_LENGTH < 1 || COMMENT_LENGTH < 1)
		err = 0;
	if (!err)
		ft_dprintf(2, "Invalid values in \"op.h\"\n");
	return (err);
}

int		list_length(t_champ *champ)
{
	return (!champ ? 0 : 1 + list_length(champ->next));
}
