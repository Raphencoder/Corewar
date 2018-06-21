/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instr_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:40:13 by abouvero          #+#    #+#             */
/*   Updated: 2018/06/20 18:36:56 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

static void			get_ocp(unsigned char byte, char *ocp)
{
	int i;
	int size;
	
	size = 8;
	i = -1;
	while (size >= 0)
		ocp[--size] = '0';
	size = 8;
	while (byte && size >= 0)
	{
		ocp[--size] = byte % 2 + 48;
		byte = byte / 2;
	}
	ocp[8] = '\0';
}

static t_param		*decode_param_type(unsigned char byte, t_instr instr)
{
	t_param *parameters;
	int		i;
	char	ocp[9];

	i = -1;
	get_ocp(byte, ocp);
//	ft_printf("{YELOW}%s{EOC}\n", ocp);
	if (!(parameters = (t_param*)ft_memalloc(sizeof(t_param) * 3)))
 		return (NULL);
//	ft_printf("OCP : %.2x %d %s\n", byte, byte, ocp);
	while (++i < g_op_tab[instr.opcode - 1].nb_param)
	{
		if (!ft_strncmp("11", &ocp[2 * i], 2))
			parameters[i].type = T_IND;
		else if (!ft_strncmp("10", &ocp[2 * i], 2))
			parameters[i].type = T_DIR;
		else if (!ft_strncmp("01", &ocp[2 * i], 2))
			parameters[i].type = T_REG;
		// else
		// 	ft_printf("{RED}OCP \"%s\" did not match{EOC}\n", &ocp[2 * i]) ;
	}
//	for (int i = 0; i < 3; i++)
//		ft_printf("OCP : PARAM%d : %d\n", i, parameters[i].type);
	return (parameters);
}


t_param			*get_params(t_instr instr)
{
	t_param	*parameters;
	int		i;
	int		cursor;

	i = -1;
	cursor = instr.process->pc + 2;
	parameters = NULL;
	if (!instr.vm || !instr.vm->map || !instr.process
	|| !(parameters = decode_param_type(instr.vm->map[(instr.process->pc + 1)
	% MEM_SIZE], instr)) || !parameters[0].type)
	{
		//ERROR("get_params for instructions : cannot decode parameter(s) type");
		return (NULL);
	}
	while (++i < 3 && parameters[i].type != 0)
	{
		parameters[i].value = byte_to_int(instr.vm->map, cursor,
		type_to_size(parameters[i].type, instr.opcode));
		cursor += type_to_size(parameters[i].type, instr.opcode);
	}
	return (parameters);
}

t_instr		instr_params(t_vm *vm, t_process *process, int opc)
{
	t_instr instr;

	instr.vm = vm;
	instr.process = process;
	instr.params = NULL;
	instr.opcode = opc;
	return (instr);
}

int			decal_pc(t_instr instr, int decal, int ret)
{
 //	if (instr.opcode - 1 < 16 && instr.opcode > 0 && ret == 0)
//		ft_printf("{RED}INSTRUCTION FAILED %s{EOC}\n", g_op_tab[instr.opcode - 1].name);
/*
	if (instr.opcode - 1 < 16 && instr.opcode > 0 && ret == 1)
		ft_printf("{GREEN}INSTRUCTION SUCCEED %s{EOC}\n", g_op_tab[instr.opcode - 1].name);
	ft_printf("ADV %d (%#.4x -> ", decal, instr.process->pc); */
	instr.process->pc = (instr.process->pc + decal) % MEM_SIZE;
	instr.process->cycles_left = -1;
	return (ret);
}

int			free_params(t_instr instr, int ret)
{
	int to_decal;
	int cursor;

	cursor = -1;
	to_decal = 2;
	if (instr.params)
	{
		while (++cursor < 3)
			to_decal += type_to_size(instr.params[cursor].type, instr.opcode);
		to_decal = to_decal != 0 ? to_decal : 1;
		decal_pc(instr, to_decal, ret);
		free(instr.params);
	}
	return (ret);
}
