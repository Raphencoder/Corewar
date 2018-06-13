/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:40:13 by abouvero          #+#    #+#             */
/*   Updated: 2018/06/06 11:00:25 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int		check_num(t_champ *ch, int num)
{
	if (num == 0)
		return (1);
	while (ch)
	{
		if (ch->id == num)
			return (0);
		ch = ch->next;
	}
	return (1);
}

int		error_mall(int err)
{
	ft_dprintf(2, "Memory allocation error\n");
	return (err);
}

t_champ	*error_file(char *str, char *file, t_champ *champ)
{
	rec_free_champs(champ);
	return (ft_dprintf(2, str, file) ? NULL : 0);
}

int		usage(int ret)
{
	ft_dprintf(2, "usage : ./corewar [-dump nbr_cycles] ");
	ft_dprintf(2, "[[-n number] champion1.cor] ...\n");
	return (ret);
}

int		illegal_opt(char *opt, int ret)
{
	ft_dprintf(2, "Illegal option : %s\n", opt);
	return (usage(ret));
}
