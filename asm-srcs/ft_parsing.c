/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:05:57 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/14 19:42:18 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem-in/libft/libft.h"
#include <stdio.h>

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

void	ft_pass_comment(char *str, int *i)
{
	while (str[*i])
	{
		while (str[*i] && str[*i] != '\n')
			*i = *i + 1;
		if (str[*i + 1] && str[*i + 1] != '#')
		{
			*i = *i + 1;
			return ;
		}
		if (str[*i + 1])
			*i = *i + 1;		
	}
}

void	ft_parsing(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	if (str[i] == '#')
		ft_pass_comment(str, &i);
	tmp = ft_strnmdup(str, i, i + 5);
	if (!ft_strequ(NAME_CMD_STRING, tmp))
	{
		ft_putendl("false");
		return ;
	}
	ft_complete_name(str, i + 5)
	ft_pass_comment(str, &i);
	ft_strdel(&tmp);
	tmp = ft_strnmdup(str, i, i + 8);
	if (!ft_strequ(COMMENT_CMD_STRING, tmp))
	{
		ft_putendl("comment false");
		return ;
	}
}
