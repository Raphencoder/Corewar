/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:49:11 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/31 17:16:50 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_print_split(char **tab)
{
	int cursor;

	cursor = 0;
	while (tab[cursor])
	{
		ft_putstr(tab[cursor]);
		ft_putchar('\n');
		cursor++;
	}
}

void	ft_print_split_fd(char **tab, int fd)
{
	int cursor;

	cursor = 0;
	while (tab[cursor])
	{
		ft_putstr_fd(tab[cursor], fd);
		ft_putchar_fd('\n', fd);
		cursor++;
	}
}
