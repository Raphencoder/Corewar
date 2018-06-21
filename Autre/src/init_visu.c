/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 16:21:02 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/20 16:35:25 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

WINDOW	*init_visu(t_visu *visu)
{
	WINDOW	*win;

	initscr();
	curs_set(0);
	start_color();
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
	visu->height = 80;
	visu->width = 250;
	visu->start_y = 1;
	visu->start_x = 20;
	win = subwin(stdscr, LINES, COLS * 0.7, 0, 0);
	wbkgd(win, COLOR_PAIR(3));
	refresh();
	return (win);
}
