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
	y = 2;
	n = 0;
	if (!(pc = (int*)ft_memalloc(sizeof(int) * (10))))
		exit (0);
	pro = vm.processes;
	ft_putchar(' ');
	ft_putnbr(vm.processes_nbr);
	ft_putchar(' ');
	while (vm.processes->next)
	{
		pc[n] = vm.processes->pc;
		vm.processes = vm.processes->next;
		n++;
		if (n > 1)
			exit (0);
	}
	vm.processes = pro;
	nodelay(stdscr,TRUE);
	ch = getch();
	if (ch == 100)
		visu->slow = visu->slow - 3000;
	if (ch == 115)
		visu->slow = visu->slow + 3000;
	if (ch == 3)
	{
		clear();
		exit (0);
	}
	if (ch == 32)
	{
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
	box(score, ACS_VLINE, ACS_HLINE);
	mvwprintw(score, 1, 5, "Cycle number : %d\n", vm.tt_cycle);
	mvwprintw(score, 3, 5, "nbr processus: %d\n", vm.processes_nbr);
	mvwprintw(score, 5, 5, "player one name :  %s\n", vm.champ->name);
	mvwprintw(score, 7, 5, "Delay :  %d\n", visu->slow);
	while (j < MEM_SIZE)
	{
		n = 0;
		while (pc[n])
		{
			if (j == pc[n])
			{
				j++;
				x += 2;
				if (!(j % 64) && j != 0){
					mvwprintw(win, y, x, "\n"); x = 5, y++;}
				else
				{
					mvwprintw(win, y, x, " ");
					x++;
				}
			}
			n++;
		}
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
		pcy = 2;
		if ((pc[n] >= 64) && pc[n] != 0)
		{
			pcx = 5 + ((pc[n] % 64) * 3);
			pcy = 2 + (pc[n] / 64);
		}
		mvprintw(pcy, pcx, "%.2x", vm.map[pc[n]]);
		//		if (vm.processes_nbr > 1)
		//			wprintw(test, "%.2x ", vm.map[pc[n]]);
		n++;
	}
	n = 0;
//	if (vm.processes_nbr > 1)
//	{
		while (n < vm.processes_nbr)
		{
			wprintw(test, "- %d -", pc[n]);
			n++;
			if (!pc[n])
			{
				wprintw(test, "//");
			}
		}
//	}
	attroff(A_STANDOUT);
	//	wborder(win, '#', '#', '#', '#', '4', '2', '4', '2');
	box(win, ACS_VLINE, ACS_HLINE);
	box(score, ACS_VLINE, ACS_HLINE);
	wrefresh(win);
	wrefresh(score);
	usleep(visu->slow);
}
