/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:36:04 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/13 18:58:59 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	is_printf_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#')
		return (1);
	return (0);
}

int	is_printf_length(char c)
{
	if (c == 'l' || c == 'h' || c == 'z' || c == 'j')
		return (1);
	return (0);
}

int	is_printf_type(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

int	check_lconv(t_plist *list)
{
	if ((list->length[0] == 'l') && !(list->length[1]))
		return (1);
	return (0);
}

int	check_hconv(t_plist *list)
{
	if ((list->length[0] == 'h') && !(list->length[1]))
		return (1);
	return (0);
}
