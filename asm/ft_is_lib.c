/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line_in_bloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:57:47 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/27 10:33:39 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_is_lib(char *str, int i)
{
	if (str[i] != 'r')
		return (0);
	i++;
	if (str[i] == '0' && (str[i + 1] == SEPARATOR_CHAR || str[i + 1] == ' ' ||
				str[i + 1] == '\n'))
		return (1);
	if (ft_isdigit(str[i]) && (ft_isdigit(str[i + 1]) || str[i + 1] == ' ' ||
str[i + 1] == '\t' || str[i + 1] == SEPARATOR_CHAR))
		return (1);
	return (0);
}
