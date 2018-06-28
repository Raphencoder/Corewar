/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:52:40 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/28 15:32:06 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_initialize(int *ok, char **res)
{
	*ok = 0;
	*res = NULL;
}

void	ft_is_not_ok(int ok, char *res, int i, char *str)
{
	if (!ok)
	{
		ft_putstr("Sorry but the label you put doesn't exist\n");
		ft_putendl(res);
		ft_strdel(&res);
		ft_is_an_error(str, i);
	}
}

char	*ft_take_the_resy(t_chain *ex)
{
	char	*res;
	char	*tmp;
	int		len;

	if (ex->content)
		len = ft_strlen(ex->content);
	else
		return (NULL);
	res = NULL;
	if (ex->content[0] == ':' ||
			(ex->content[0] == '%' && ex->content[1] == ':'))
	{
		if (ex->content[0] == ':')
			res = ft_strnmdup(ex->content, 1, len);
		else
			res = ft_strnmdup(ex->content, 2, len);
		tmp = res;
		res = ft_strjoin(tmp, ":");
		ft_strdel(&tmp);
	}
	return (res);
}

t_chain	*ft_next(t_chain *block, char *res, int *ok)
{
	t_chain *start;

	start = block;
	while (block)
	{
		if (ft_strequ(block->category, "LABEL") &&
				ft_strequ(block->content, res))
		{
			block = start;
			*ok = 1;
			break ;
		}
		block = block->next;
	}
	return (block);
}

void	ft_verify_label(char *str, t_chain *block)
{
	int		ok;
	char	*res;
	t_chain	*ex;

	ex = block;
	ft_initialize(&ok, &res);
	while (ex)
	{
		if (res)
			ft_strdel(&res);
		if ((res = ft_take_the_resy(ex)))
		{
			block = ft_next(block, res, &ok);
			ft_is_not_ok(ok, res, ex->line, str);
		}
		ex = ex->next;
		ok = 0;
	}
	ft_strdel(&res);
}
