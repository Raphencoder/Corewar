/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 12:36:15 by mfonteni          #+#    #+#             */
/*   Updated: 2018/06/20 15:05:01 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Glosssaire :
 * OCP = Octet de Codage des Parametres
 * ***********************************************************
 * TODO: 
 * Tests, tests, tests and another tests
**/

#include "../include/corewar.h"
#define DECAL 3

int	live(t_instr instr)
{
	t_champ *thischamp;
	//INFO("LIVE");
	instr.process->alive = 1;
	instr.vm->lives++;
	if (!instr.vm || !instr.vm->champ
	|| !(thischamp = get_champ_by_num(instr.vm->champ,
	byte_to_int(instr.vm->map, instr.process->pc + 1, 4))))
		return (decal_pc(instr, 5, 0));
	thischamp->lives++;
	instr.vm->last = thischamp;
	// ft_printf("P %4d | %s %d\n", instr.process->id, "live", byte_to_int(instr.vm->map, instr.process->pc + 1, 4));
//	ft_printf("Player %d (%s) is said to be alive\n", thischamp->id, thischamp->name);
	//ft_printf("[%d] - {BLUE}Champion %s (id:%d) is alive{EOC}\n",
	//thischamp->lives, thischamp->name, thischamp->id);
	return (decal_pc(instr, 5, 1));
}

int	ld(t_instr instr)
{
	//INFO("LD");
	instr.params = get_params(instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[1].value))
		return (free_params(instr, 0));
	if (instr.params[0].type == T_DIR)
	{
		instr.process->reg[instr.params[1].value] = instr.params[0].value;
		// ft_printf("P %4d | %s r%d %d\n", instr.process->id, "ld", instr.params[1].value + 1, instr.params[0].value);
	}
	else
	{
		instr.process->reg[instr.params[1].value]
		= byte_to_int(instr.vm->map,
		get_address(instr.process->pc + (instr.params[0].value % IDX_MOD)), 4);
		// ft_printf("P %4d | %s r%d %d\n", instr.process->id, "ld", instr.params[1].value + 1, instr.process->reg[instr.params[1].value]);
	}
	instr.process->carry = instr.process->reg[instr.params[1].value] == 0;
	return (free_params(instr, 1));
}

int	st(t_instr instr)
{
	//INFO("ST");
	instr.params = get_params(instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[0].value))
		return (free_params(instr, 0));
	if (instr.params[1].type == T_REG && instr.params[1].value <= REG_NUMBER)
	{
		instr.process->reg[instr.params[1].value]
		= instr.process->reg[instr.params[0].value];
		// ft_printf("P %4d | %s r%d %d\n", instr.process->id, "st", instr.params[1].value + 1, instr.process->reg[instr.params[0].value]);
	}
	else if (instr.params[1].type == T_IND)
	{
		int_to_bytes(instr.process->reg[instr.params[0].value],
		get_address(instr.process->pc + (instr.params[1].value % IDX_MOD)),
		instr.vm->map);
		// ft_printf("P %4d | %s r%d %d\n", instr.process->id, "st", instr.params[1].value + 1, instr.process->reg[instr.params[0].value]);
	}
	else
		return (free_params(instr, 0));
	return (free_params(instr, 1));
}

int	add(t_instr instr)
{
	//INFO("ADD");
	instr.params = get_params(instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[0].value)
	|| !valid_reg(--instr.params[1].value)
	|| !valid_reg(--instr.params[2].value))
		return (free_params(instr, 0));
	instr.process->reg[instr.params[2].value]
	= instr.process->reg[instr.params[0].value]
	+ instr.process->reg[instr.params[1].value];
	// ft_printf("P %4d | %s r%d r%d r%d\n", instr.process->id, "add", instr.params[0].value + 1, instr.params[1].value + 1, instr.params[2].value + 1);
	instr.process->carry = instr.process->reg[instr.params[2].value] == 0;
	return (free_params(instr, 1));
}

int	sub(t_instr instr)
{
	//INFO("SUB");
	instr.params = get_params(instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[0].value)
	|| !valid_reg(--instr.params[1].value)
	|| !valid_reg(--instr.params[2].value))
		return (free_params(instr, 0));
	instr.process->reg[instr.params[2].value]
	= instr.process->reg[instr.params[0].value]
	- instr.process->reg[instr.params[1].value];
	// ft_printf("P %4d | %s r%d r%d r%d\n", instr.process->id, "sub", instr.params[0].value + 1, instr.params[1].value + 1, instr.params[2].value + 1);
	instr.process->carry = instr.process->reg[instr.params[2].value] == 0;
	return (free_params(instr, 1));
}

int	and(t_instr instr)
{
	//INFO("AND");
	instr.params = get_params(instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[2].value) || !convert_params(instr, 2))
		return (free_params(instr, 0));
	instr.process->reg[instr.params[2].value]
	= instr.params[0].value & instr.params[1].value;
	// ft_printf("P %4d | %s %d %d r%d\n", instr.process->id, "and", instr.process->reg[instr.params[0].value], instr.process->reg[instr.params[1].value], instr.params[2].value + 1);
	instr.process->carry = instr.process->reg[instr.params[2].value] == 0;
	return (free_params(instr, 1));
}

int	or(t_instr instr)
{
	//INFO("OR");
	instr.params = get_params(instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[2].value) || !convert_params(instr, 2))
		return (free_params(instr, 0));
	instr.process->reg[instr.params[2].value]
	= instr.params[0].value | instr.params[1].value;
	instr.process->carry = instr.process->reg[instr.params[2].value] == 0;
	// ft_printf("P %4d | %s %d %d r%d\n", instr.process->id, "or", instr.process->reg[instr.params[0].value], instr.process->reg[instr.params[1].value], instr.params[2].value + 1);
	return (free_params(instr, 1));
}

int	xor(t_instr instr)
{
	//INFO("XOR");
	instr.params = get_params(instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[2].value) || !convert_params(instr, 2))
		return (free_params(instr, 0));
	instr.process->reg[instr.params[2].value]
	= instr.params[0].value ^ instr.params[1].value;
	instr.process->carry = instr.process->reg[instr.params[2].value] == 0;
	return (free_params(instr, 1));
}
//TODO: Check this one :
int	zjmp(t_instr instr)
{
	//INFO("ZJMP");
	if (instr.process->carry == 0)
	{
		// ft_printf("P %4d | %s %d FAILED\n", instr.process->id, "zjmp", get_address(instr.process->pc + byte_to_int(instr.vm->map, instr.process->pc + 1, 2) % IDX_MOD));
		return (decal_pc(instr, DECAL, 0));
	}
	instr.process->pc = get_address(instr.process->pc +
		byte_to_int(instr.vm->map, instr.process->pc + 1, 2) % IDX_MOD);
	// ft_printf("P %4d | %s %d OK\n", instr.process->id, "zjmp", get_address(instr.process->pc + byte_to_int(instr.vm->map, instr.process->pc + 1, 2) % IDX_MOD));
	instr.process->cycles_left = -1;
	// SUCCESS("INSTRUCTION SUCCEED zjmp");
	return (1);
}

int	ldi(t_instr instr)
{
	//INFO("LDI");
	instr.params = get_params(instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[2].value) || !convert_params(instr, 2))
		return (free_params(instr, 0));
	instr.process->reg[instr.params[2].value]
	= instr.vm->map[get_address(instr.process->pc
	+ (instr.params[0].value + instr.params[1].value) % IDX_MOD)];
	// ft_printf("P %4d | %s %d %d r%d\n", instr.process->id, "ldi", instr.process->reg[instr.params[0].value], instr.process->reg[instr.params[1].value], instr.params[2].value + 1);
	instr.process->carry = instr.process->reg[instr.params[2].value] == 0;
	return (free_params(instr, 1));
}

int	sti(t_instr instr)
{
	//INFO("STI");
	instr.params = get_params(instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[0].value)
	|| !convert_params_start(instr, 1, 3))
		return (free_params(instr, 0));
	int_to_bytes(instr.process->reg[instr.params[0].value],
	get_address(instr.process->pc +
	(instr.params[1].value + instr.params[2].value) % IDX_MOD), instr.vm->map);
	// ft_printf("P %4d | %s r%d %d %d\n", instr.process->id, "sti", instr.params[0].value + 1, instr.params[1].value, instr.params[2].value);
	// print_param(instr.params);
	return (free_params(instr, 1));
}

int	core_fork(t_instr instr)
{
	int i;

	i = -1;
	//INFO("FORK");
	add_process(instr.vm, get_address(instr.process->pc +
	(byte_to_int(instr.vm->map, instr.process->pc + 1, 2) % IDX_MOD)),
	instr.process->reg[1]);
	instr.vm->processes->carry = instr.process->carry;
	instr.vm->processes->alive = 1;
	// ft_printf("P %4d | %s %d (%d)\n", instr.process->id, "fork",byte_to_int(instr.vm->map, instr.process->pc + 1, 2), instr.vm->processes->pc);
	while (++i < REG_NUMBER)
		instr.vm->processes->reg[i] = instr.process->reg[i];
	return (decal_pc(instr, DECAL, 1));
}

int	lld(t_instr instr)
{
	//INFO("LLD");
	instr.params = get_params(instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[1].value))
		return (free_params(instr, 0));
	if (instr.params[0].type == T_DIR)
	{
		instr.process->reg[instr.params[1].value] = instr.params[0].value;
		// ft_printf("P %4d | %s %d r%d\n", instr.process->id, "lld", instr.params[0].value, instr.params[1].value + 1);
	}
	else
	{
		instr.process->reg[instr.params[1].value]
		= byte_to_int(instr.vm->map,
		get_address(instr.process->pc + instr.params[0].value), 4);
		// ft_printf("P %4d | %s %d r%d\n", instr.process->id, "lld", instr.process->reg[instr.params[1].value], instr.params[1].value + 1);
	}
	instr.process->carry = instr.process->reg[instr.params[1].value] == 0;
	return (free_params(instr, 1));
}

int	lldi(t_instr instr)
{
	//INFO("LLDI");
	instr.params = get_params(instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[2].value)
	|| !convert_params_unrestrained(instr, 2))
		return (free_params(instr, 0));
	instr.process->reg[instr.params[2].value]
	= instr.vm->map[get_address(instr.process->pc
	+ (instr.params[0].value + instr.params[1].value))];
	// ft_printf("P %4d | %s %d %d r%d\n", instr.process->id, "lldi", instr.params[0].value, instr.params[1].value, instr.params[2].value + 1);
	return (free_params(instr, 1));
}

int	core_lfork(t_instr instr)
{
	int i;

	i = -1;
	//INFO("CORE_LFORK");
	add_process(instr.vm, get_address(instr.process->pc +
	byte_to_int(instr.vm->map, instr.process->pc + 1, 2)),
	instr.process->reg[1]);
	// ft_printf("P %4d | %s %d (%d)\n", instr.process->id, "lfork", byte_to_int(instr.vm->map, instr.process->pc + 1, 2), instr.vm->processes->pc);
	instr.vm->processes->carry = instr.process->carry;
	instr.vm->processes->alive = instr.process->alive;
	while (++i <= REG_NUMBER)
		instr.vm->processes->reg[i] = instr.process->reg[i];
	return (decal_pc(instr, DECAL, 1));
}

int	aff(t_instr instr)
{
	//INFO("AFF"); 
	instr.params = get_params(instr);
	if (!compare_params(instr.params, instr.opcode)
	|| !valid_reg(--instr.params[0].value)
	|| !get_champ_by_num(instr.vm->champ, instr.process->reg[1]))
		return (free_params(instr, 0));
	//ft_printf("{CYAN}[%d] - %s:%c{EOC}\n", instr.process->reg[1],
	//get_champ_by_num(instr.vm->champ, instr.process->reg[1])->name,
	//instr.process->reg[instr.params[0].value]);
	instr.process->carry = instr.process->reg[instr.params[0].value] == 0;
	return (free_params(instr, 1));
}
