/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:40:13 by mfonteni          #+#    #+#             */
/*   Updated: 2018/06/12 17:36:36 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

//TODO: test if unsigned long is valid with all cases
int	byte_to_int(unsigned char *map, int cursor, int amount_of_bytes)
{
	unsigned long	size;
	int	i;

	i = -1;
	size = 0;
	// ft_printf("{YELLOW}amount:%d{EOC}\n", amount_of_bytes);

	while (++i < amount_of_bytes)
	{
		size |= map[(cursor + i) % MEM_SIZE];
		// ft_printf("{YELLOW}%d{EOC}", map[(cursor + i)]);
		// ft_putchar('\n');
		size <<= 8;
	}
//	ft_printf("byte_to_int returns:%d\n", size >> 8);
	return (size >> 8);
}

int get_address(int value)
{
	if (value < 0)
		value = MEM_SIZE + (value % MEM_SIZE);
	return (value % MEM_SIZE);
}

int	int_to_bytes(int n, int cursor, unsigned char *map)
{
	int decal;

	if (!map)
		return (0);
	decal = -1;
	while (++decal < 4)
		map[(cursor + decal) % MEM_SIZE] = (n >> (24 - (decal * 8))) & 0xFF;
	return (1);
}

