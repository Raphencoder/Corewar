/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:40:13 by abouvero          #+#    #+#             */
/*   Updated: 2018/06/12 12:05:12 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int			swap_ch(t_champ *fchamp, t_champ *schamp)
{
	t_champ	*tmp;

	if (!(tmp = (t_champ*)ft_memalloc(sizeof(t_champ))))
		return (error_mall(0));
	tmp->id = fchamp->id;
	tmp->size = fchamp->size;
	ft_strcpy(tmp->name, fchamp->name);
	ft_strcpy(tmp->comment, fchamp->comment);
	tmp->code = fchamp->code;
	fchamp->id = schamp->id;
	fchamp->size = schamp->size;
	ft_strcpy(fchamp->name, schamp->name);
	ft_strcpy(fchamp->comment, schamp->comment);
	fchamp->code = schamp->code;
	schamp->id = tmp->id;
	schamp->size = tmp->size;
	ft_strcpy(schamp->name, tmp->name);
	ft_strcpy(schamp->comment, tmp->comment);
	schamp->code = tmp->code;
	ft_memdel((void**)&tmp);
	return (1);
}

int			sort_champs(t_vm *vm)
{
	t_champ *ch;

	ch = vm->champ;
	while (ch->next)
	{
		if (ch->id > ch->next->id)
			swap_ch(ch, ch->next);
		ch = ch->next;
	}
	return (1);
}

static int	introduce_champs(t_champ *champs)
{
	if (list_length(champs) > MAX_PLAYERS)
	{
		ft_dprintf(2, "Too much champs loaded\n");
		return (0);
	}
	ft_printf("Introducing contestants...\n");
	while (champs)
	{
		ft_printf("* Player %d, weighing %d bytes, ", champs->id, champs->size);
		ft_printf("\"%s\" (\"%s\") !\n", champs->name, champs->comment);
		champs = champs->next;
	}
	return (1);
}

static int	load_champs(t_vm *vm, int index)
{
	t_champ *ch;
	int		size;
	int		i;
	int		sta;

	sta = 0;
	ch = vm->champ;
	while (ch)
	{
		i = -1;
		if (!(add_process(vm, sta % MEM_SIZE, ch->id)))
			return (0);
		size = ch->size;
		while (++i < size)
			vm->map[sta + i] = ch->code[i];
		sta += index;
		ch = ch->next;
	}
	return (1);
}

t_vm		*init_vm(int argc, char **argv)
{
	t_vm		*vm;

	if (!(vm = (t_vm*)ft_memalloc(sizeof(t_vm))))
	{
		error_mall(0);
		return (NULL);
	}
	vm->last = NULL;
	vm->lives = 0;
	vm->processes_nbr = 0;
	vm->dump = -1;
	vm->cycle = 0;
	if (!init_champs(argc, argv, vm))
		return (free_vm(vm));
	else if (!(vm->map = (unsigned char *)ft_memalloc(MEM_SIZE)))
	{
		error_mall(0);
		return (free_vm(vm));
	}
	vm->processes = NULL;
	if (!(load_champs(vm, MEM_SIZE / list_length(vm->champ))))
		return (free_vm(vm));
	if (!introduce_champs(vm->champ))
		return (free_vm(vm));
	return (vm);
}
