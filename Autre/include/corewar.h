/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:40:13 by mfonteni          #+#    #+#             */
/*   Updated: 2018/06/12 16:12:36 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COREWAR_H
#define COREWAR_H

#include "../libft/includes/libft.h"
#include "op.h"
#include <ncurses.h>
#include <unistd.h>
#include <fcntl.h>

/********************DEBUG KINGDOM*********************/
#define ERROR(message) ft_printf("{RED}%s{EOC}\n", message)
#define SUCCESS(message) ft_printf("{GREEN}%s{EOC}\n", message)
#define INFO(message) ft_printf("{BLUE}%s{EOC}\n", message)
#define INFONUM(message) ft_printf("{BLUE}%d{EOC}\n", message)
/******************************************************/

//REMOVE
int	mem_dump(unsigned char *map);

typedef struct			s_champ
{
	int					id;
	int					size;
	unsigned int		lives;
	char 				name[PROG_NAME_LENGTH + 1];
	char 				comment[COMMENT_LENGTH + 1];
	unsigned char		*code;
	struct s_champ		*next;
}						t_champ;

typedef struct			s_process
{
	int					alive;
	int					pc;
	int					carry;
	int					reg[REG_NUMBER];
	int					cycles_left;
	struct s_process	*next;
}						t_process;

typedef struct			s_param
{
	int					value;
	int					type;
}						t_param;

typedef struct			s_instr
{
	struct s_vm			*vm;
	t_process			*process;
	t_param				*params;
	int					opcode;
}						t_instr;

typedef struct			s_vm
{
	unsigned int		lives;
	t_champ				*last;
	int					dump;
	int					processes_nbr;
	int					cycle;
	unsigned char		*map;
	int 				(*instr_tab[16])(t_instr);
	struct s_champ		*champ;
	struct s_process	*processes;
}						t_vm;

//run.c
int 					run(t_vm *vm);

//free.c
t_vm					*free_vm(t_vm *vm);
t_champ					*rec_free_champs(t_champ *champs);

//init_champs.c
int						init_champs(int ac, char **av, t_vm *vm);

//init.c
t_vm					*init_vm(int argc, char **argv);
int						sort_champs(t_vm *vm);

//get_champ.c
t_champ					*parse_champ(char *file_name , t_champ *champ);
int						fill_id_champs(t_vm *vm);

//error.c
int						usage(int ret);
t_champ					*error_file(char *str, char *file, t_champ *champ);
int						error_mall(int err);
int 					illegal_opt(char *opt, int ret);
int						check_num(t_champ *ch, int num);

//getters.c
t_champ					*get_champ_by_num(t_champ *list, int num);

//process.c
int						add_process(t_vm *vm, int pc, int id);
void					check_process(t_vm *vm);

//option.c
int						opt(char **av, int ac, int *i, t_vm *vm);

//init_tools.c
int						known_opt(char *opt);
int						check_inputs(void);
int						list_length(t_champ *champ);

//instr_params.c
t_param					*decode_param_type(unsigned char ocp);
t_param					*get_params(t_vm *vm, t_process *process, int opcode);
t_instr					instr_params(t_vm *vm, t_process *process, int opc);
int						continue_process(t_vm *vm, t_process *process);

//instr_params_checks.c
int						compare_params(t_param *params, int opcode);

//instructions.c
int						continue_process(t_vm *vm, t_process *process);
int 					type_to_size(int type, int oct);
int						byte_to_int(unsigned char *map, int cursor,
						int amount_of_bytes);
int						int_to_bytes(int n, int cursor, unsigned char *map);
int						free_params(t_instr instr, int ret);
void					convert_params(t_instr instr, int limit);
void					convert_params_unrestrained(t_instr instr, int limit);
int						decal_pc(t_process *process, int decal, int ret);
void					convert_params_start(t_instr instr, int start,
						int limit);
int						valid_reg(int reg);
int						get_address(int value);
int						live(t_instr instr);
int						ld(t_instr instr);
int						st(t_instr instr);
int						add(t_instr instr);
int						sub(t_instr instr);
int						and(t_instr instr);
int						or(t_instr instr);
int						xor(t_instr instr);
int						zjmp(t_instr instr);
int						ldi(t_instr instr);
int						sti(t_instr instr);
int						core_fork(t_instr instr);
int						lld(t_instr instr);
int						lldi(t_instr instr);
int						core_lfork(t_instr instr);
int						aff(t_instr instr);

#endif
