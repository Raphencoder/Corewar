/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 11:22:38 by abouvero          #+#    #+#             */
/*   Updated: 2018/06/19 13:50:53 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"
#include <ncurses.h>

static void	init_instr_tab(t_vm *vm)
{
	vm->instr_tab[0] = &live;
	vm->instr_tab[1] = &ld;
	vm->instr_tab[2] = &st;
	vm->instr_tab[3] = &add;
	vm->instr_tab[4] = &sub;
	vm->instr_tab[5] = &and;
	vm->instr_tab[6] = &or;
	vm->instr_tab[7] = &xor;
	vm->instr_tab[8] = &zjmp;
	vm->instr_tab[9] = &ldi;
	vm->instr_tab[10] = &sti;
	vm->instr_tab[11] = &core_fork;
	vm->instr_tab[12] = &lld;
	vm->instr_tab[13] = &lldi;
	vm->instr_tab[14] = &core_lfork;
	vm->instr_tab[15] = &aff;
}

static int	exec_process(t_process *process, t_vm *vm)
{
	unsigned char	opc;

	opc = vm->map[process->pc];
	if (opc < 1 || opc > 16)
		return (decal_pc(process, 1, 0));
	if (process->cycles_left == -1)
	{
		process->cycles_left = g_op_tab[opc - 1].nb_cycle - 1;
		return (0);
	}
	//	ft_printf("OCP : %d\n", opc);
	vm->instr_tab[opc - 1](instr_params(vm, process, opc));
	//	ft_printf("NEW PC : %d\n", process->pc);
	return (1);
}

int	mem_dump(unsigned char *map)
{
	int		i;

	i = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%.2x", map[i++]);
		if (!(i % 32) && i != 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
	}
	return (1);
}

static void	exec_processes(t_process *process, t_vm *vm)
{
	if (!process)
		return ;
	while (process)
	{
		if (process->cycles_left > 0)
			process->cycles_left--;
		else
			exec_process(process, vm);
		process = process->next;
	}
}

void		ft_visu(t_vm *vm, int i, WINDOW *win, WINDOW *box, unsigned char *clone)
{
	int ch;
	int	j;
	int	y;
	int x;

	x = 0;
	j = 0;
	i = 0;
	y = 1;
	nodelay(stdscr,TRUE);
	ch = getch();
	if (ch == 95)
		i = i - 1000;
	if (ch == 43)
		i = i + 1000;
	if (i <= 0)
		i = 30000;
	if (ch == 3)
	{
		clear();
		exit (0);
	}
	if (ch == 45)
		i = 2000;
	wrefresh(win);
	box(box, 0, 0);
	mvwprintw(win, 0, 0, "cycle numero : %d\n", vm->cycle);
	attron(UNDERLINE);
		
	attroff(UNDERLINE);
	while (j < MEM_SIZE)
	{
		if (x > 200)
		{
			x = 0;
			y++;
		}		
		if (clone[j] != vm->map[j] || vm->cycle == 0)
		{
			if (vm->cycle != 0)
				wprintw(win, "gere");
			wprintw(win, "%.2x", vm->map[j++]);
			if (!(j % 64) && j != 0)
				wprintw(win, "\n");
			else
				wprintw(win, " ");
			x++;
		}
		else{
			j++; x++;}
		if (clone[j] != vm->map[j] && vm->cycle != 0)
			wprintw(win, "gere");

		wrefresh(win);
	}
	usleep(i);
}

int			run(t_vm *vm)
{
	int		ctd;
	int		check;
	int		i;
	WINDOW	*win;
	WINDOW	*box;
	int		height;
	int		width;
	int		start_y;
	int		start_x;
	unsigned char *clone;
	int		cpc;

	i = 300;
	check = 0;
	init_instr_tab(vm);
	ctd = CYCLE_TO_DIE;
	initscr();
	height = 80;
	width =	200;
	start_y = 5;
	start_x = 20;
	win = newwin(height, width, start_y, start_x);
	box = newwin(height + 10, width + 10, 2, 10); 
	refresh();
	wrefresh(win);
	while (vm->processes_nbr && ctd > 0)
	{
		//		ft_printf("CYCLE : %d\n", vm->cycle);
		if (vm->cycle == vm->dump)
			return (mem_dump(vm->map));
		if (!(vm->cycle % ctd) && vm->cycle)
		{
			check_process(vm);
			if (++check == MAX_CHECKS || vm->lives >= NBR_LIVE)
			{
				vm->lives = 0;
				check = 0;
				ctd -= CYCLE_DELTA;
			}
		}
		ft_visu(vm, i, win, box, clone);
		clone = vm->map;
		cpc = vm->processes->pc;
		exec_processes(vm->processes, vm);
		vm->cycle++;
	}
	endwin();
	return (1);
}
