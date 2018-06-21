/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu_run.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:24:18 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/20 16:31:18 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

void	print_header(WINDOW *win)
{
	int	x_offset;

	x_offset = 70;
	wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	wattron(win, COLOR_PAIR(1));
	mvwprintw(win, 1, x_offset, HEADER_LINE_1);
	mvwprintw(win, 2, x_offset, HEADER_LINE_2);
	mvwprintw(win, 3, x_offset, HEADER_LINE_3);
	mvwprintw(win, 4, x_offset, HEADER_LINE_4);
	mvwprintw(win, 5, x_offset, HEADER_LINE_5);
	wattroff(win, COLOR_PAIR(1));
	wrefresh(win);
}

void	visu_run(t_vm vm, WINDOW *win, t_visu *visu, WINDOW *score, WINDOW *test)
{
	int ch;
	int j;
	int *pc;
	int	n;
	int pcx;
	int pcy;
	int x;
	int y;
	t_process *pro;

	j = 0;
	x = 5;
	y = 7;
	n = 0;
	print_header(win);
	if (!(pc = (int*)ft_memalloc(sizeof(int) * (10))))
		exit (0);
	pro = vm.processes;
	//ft_putchar(' ');
//	ft_putnbr(vm.processes_nbr);
//	ft_putchar(' ');
	while (n < vm.processes_nbr)
	{
		pc[n] = vm.processes->pc;
//		wprintw(test, "- %d -", pc[n]);
		vm.processes = vm.processes->next;
		n++;
	}
	vm.processes = pro;
	nodelay(stdscr,TRUE);
	ch = getch();
	if (ch == 100)
	{
		if (visu->slow > 0)
			visu->slow = visu->slow - 3000;
	}
	if (ch == 115)
		visu->slow = visu->slow + 3000;
	if (ch == 3)
	{
		clear();
		exit (0);
	}
	if (ch == 32)
	{
		mvwprintw(score, 1, 5, "***PAUSED***");
		wrefresh(score);
		nodelay(stdscr, FALSE);
		while (ch != 112)
			ch = getch();
	}
	if (ch == 114)
		visu->slow = 300000;
	if (ch == 116)
		visu->slow = 0;
	if (ch == 49)
	{	
		while (ch != 49)
			ch = getch();
	}
	//	wborder(win, '#', '#', '#', '#', '4', '2', '4', '2');
	init_color(COLOR_WHITE, 255, 255, 255);
	box(score, ACS_VLINE, ACS_HLINE);
	wattron(score, COLOR_PAIR(COLOR_WHITE));
	mvwprintw(score, 1, 5, "**RUNNING**");
	mvwprintw(score, 3, 5, "Cycle number : %d\n", vm.tt_cycle);
	mvwprintw(score, 5, 5, "nbr processus: %d\n", vm.processes_nbr);
	mvwprintw(score, 7, 5, "Player one name :  %s\n", vm.champ->name);
	mvwprintw(score, 9, 5, "Delay :  %d\n", visu->slow);
	wrefresh(win);
	wattroff(score, COLOR_PAIR(COLOR_WHITE));
	while (j < MEM_SIZE)
	{
		mvwprintw(win, y, x, "%.2x", vm.map[j++]);
		x += 2;
		if (!(j % 64) && j != 0){
			mvwprintw(win, y, x, "\n"); x = 5, y++;}
		else{
			mvwprintw(win, y, x, " ");x++;}
	}
	wrefresh(test);
	n = 0;
	attron(A_STANDOUT);
	while (n < vm.processes_nbr)
	{
		pcx = 5 + (pc[n] * 3);
		pcy = 7;
		if ((pc[n] >= 64) && pc[n] != 0)
		{
			pcx = 5 + ((pc[n] % 64) * 3);
			pcy = 7 + (pc[n] / 64);
		}
		mvprintw(pcy, pcx, "%.2x", vm.map[pc[n]]);
		n++;
	}
	n = 0;
	attroff(A_STANDOUT);
	wborder(win, '#', '#', '#', '#', '#', '#', '#', '#');
	box(score, ACS_VLINE, ACS_HLINE);
	wrefresh(win);
	wrefresh(score);
	usleep(visu->slow);
}
