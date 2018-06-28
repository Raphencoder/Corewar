/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkbegin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:07:04 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/28 15:12:48 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int	ft_checkbegin(char *str, int *i)
{
	if (!str || !str[*i] || !ft_isascii(str[*i]))
		ft_is_an_error(str, *i);
	while (str[*i] <= 32 || str[*i] == COMMENT_CHAR || str[*i] == ';')
	{
		if (str[*i] == COMMENT_CHAR || str[*i] == ';')
			ft_pass_comment(str, i);
		if (str[*i] <= 32)
		{
			ft_pass_space(str, i);
			*i = *i + 1;
		}
		if (str[*i] == '\n')
			*i = *i + 1;
	}
	return (0);
}
