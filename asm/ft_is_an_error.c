/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_an_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:07:56 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/22 12:56:22 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/asm.h"

void	ft_is_an_error(char *str, int i)
{
	int j;
	int	col;
	int	nb_line;
	
	j = 0;
	col = 1;
	nb_line = 1;
	while (j != i)
	{
		if (str[j] == '\n')
		{
			nb_line++;
			col = 1;
		}
		j++;
		col++;
	}
	col--;
	ft_putstr("Error line ");
	ft_putnbr(nb_line);
	ft_putstr(" column ");
	ft_putnbr(col);
	ft_putchar('\n');
	exit (0);
}
