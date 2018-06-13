/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_params_check.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/04 11:43:01 by mfonteni          #+#    #+#             */
/*   Updated: 2018/06/12 16:12:22 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int compare_params(t_param *params, int opcode)
{
	int i;

	i = -1;
	if (!params || --opcode < 0 || opcode > 17)
	{
		INFONUM(opcode);
		ERROR("Compare params : wrong opcode or null params");
		return (0);
	}
	while (++i < 3)
	{
		if ((!g_op_tab[opcode].type_param[i] && params[i].type)
		|| !((params[i].type & g_op_tab[opcode].type_param[i])))
		{
			ft_printf("{RED}Wrong param type for instruction %s{EOC}\n", g_op_tab[opcode].name);
			ft_printf("{RED}Param number %d code %d{EOC}\n", i, params[i].type);
			return (0);
		}
	}
	return (1);
}

void convert_params(t_instr instr, int limit)
{
	int i;

	i = -1;
	if (!instr.params)
		return ;
	while (++i < limit)
	{
		if (instr.params[i].type == T_REG)
			instr.params[i].value = instr.process->reg[instr.params[i].value];
		else if (instr.params[i].type == T_IND)
			instr.params[i].value =
			byte_to_int(instr.vm->map, get_address((instr.process->pc
			+ (instr.params[i].value % IDX_MOD))), DIR_SIZE);
	}
}

void convert_params_start(t_instr instr, int start, int limit)
{
	int i;

	i = start - 1;
	if (!instr.params)
		return ;
	while (++i < limit)
	{
		if (instr.params[i].type == T_REG)
			instr.params[i].value
			= instr.process->reg[instr.params[i].value % REG_SIZE];
		else if (instr.params[i].type == T_IND)
			instr.params[i].value =
			byte_to_int(instr.vm->map, get_address((instr.process->pc
			+ (instr.params[i].value % IDX_MOD))), DIR_SIZE);
	}
}

void convert_params_unrestrained(t_instr instr, int limit)
{
	int i;

	i = -1;
	if (!instr.params)
		return ;
	while (++i < limit)
	{
		if (instr.params[i].type == T_REG)
			instr.params[i].value = instr.process->reg[instr.params[i].value];
		else if (instr.params[i].type == T_IND)
			instr.params[i].value =
			byte_to_int(instr.vm->map, get_address((instr.process->pc
			+ instr.params[i].value)), DIR_SIZE);
	}
}

int type_to_size(int type, int opc)
{
	if (type == T_DIR)
		return (g_op_tab[opc - 1].oct ? 2 : DIR_SIZE);
	else if (type == T_IND)
		return (IND_SIZE);
	else if (type == T_REG)
		return (1);
	return (0);
}

int valid_reg(int reg)
{
	if (reg < REG_NUMBER && reg >= 0)
		return (1);
	return (0);
}