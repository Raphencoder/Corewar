/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pass_comment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 10:42:10 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/24 13:31:26 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/asm.h"

void	ft_pass_comment(char *str, int *i)
{
	while (str[*i])
	{
		while (str[*i] && str[*i] != '\n')
			*i = *i + 1;
		if (str[*i + 1] && (str[*i + 1] != '#' && str[*i + 1] != ';' &&
str[*i + 1] != '\n'))
		{
			*i = *i + 1;
			return ;
		}
		if (str[*i + 1])
			*i = *i + 1;
	}
}
