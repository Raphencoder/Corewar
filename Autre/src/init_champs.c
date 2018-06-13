/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_champs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:32:13 by abouvero          #+#    #+#             */
/*   Updated: 2018/06/12 12:15:25 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

static int		check_header(t_champ *champs, char *file)
{
	while (champs->next)
		champs = champs->next;
	if (!*champs->name)
	{
		ft_dprintf(2, "Invalid header in \"%s\" : unnamed champion\n", file);
		return (0);
	}
	if (!*champs->comment)
	{
		ft_dprintf(2, "Invalid header in \"%s\" : uncommented champion\n"\
																	, file);
		return (0);
	}
	return (1);
}

static int		check_champ_ext(char *name)
{
	int		len;

	len = ft_strlen(name);
	if (len > 4 && name[len - 1] == 'r' && name[len - 2] == 'o' &&
					name[len - 3] == 'c' && name[len - 4] == '.')
		return (1);
	return (0);
}

static t_champ	*fill_new_champ(t_champ *champ, char *file)
{
	champ->id = 0;
	champ->size = 0;
	champ->lives = 0;
	champ->next = NULL;
	if (!(parse_champ(file, champ)))
		return (NULL);
	return (champ);
}

static t_champ	*champs_push(t_champ *champ, char *file, int num)
{
	t_champ	*new;
	t_champ	*beg;

	beg = champ;
	if (!(new = (t_champ *)ft_memalloc(sizeof(t_champ))))
	{
		error_mall(0);
		return (rec_free_champs(champ));
	}
	if (!(new = fill_new_champ(new, file)))
		return (rec_free_champs(champ));
	if (!check_num(champ, num))
	{
		ft_dprintf(2, "\"%s\" : %d already taken\n", file, num);
		return (rec_free_champs(champ));
	}
	new->id = num;
	if (!champ)
		return (new);
	while (champ->next)
		champ = champ->next;
	champ->next = new;
	return (beg);
}

int				init_champs(int ac, char **av, t_vm *vm)
{
	int		i;
	int		num;

	i = 0;
	while (++i < ac)
	{
		num = 0;
		if (*av[i] == '-')
		{
			if ((num = opt(av, ac, &i, vm)) == -1)
				return (0);
			else if (num == -2)
				return (vm->champ ? 1 : 0);
		}
		if (!check_champ_ext(av[i]))
		{
			ft_dprintf(2, "\"%s\" : '.cor' file expected\n", av[i]);
			return (usage(0));
		}
		if (!(vm->champ = champs_push(vm->champ, av[i], num)))
			return (0);
		if (!(check_header(vm->champ, av[i])))
			return (0);
	}
	return (fill_id_champs(vm));
}
