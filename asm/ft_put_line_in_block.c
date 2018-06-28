/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_line_in_bloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:57:47 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/28 13:22:26 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

t_chain	*ft_inc(int *i, int *nb_arg, t_chain *b)
{
	*i = *i + 1;
	*nb_arg = *nb_arg - 1;
	if (!(b->next = ft_memalloc(sizeof(t_chain))))
		exit(0);
	return (b->next);
}

int		ft_check_if_instruction(t_chain *block)
{
	int i;

	i = 0;
	(void)block;
	while (i < 16)
	{
		if (ft_strequ(op_tab[i].str, block->content))
		{
			block->nb_op_tab = i;
			return (1);
		}
		i++;
	}
	return (0);
}

int		ft_take_nb_argument(char *str, int i)
{
	int nb_separator;
	int	smth;

	smth = 0;
	nb_separator = 0;
	while (str[i] && (str[i] != '\n' &&
				str[i] != COMMENT_CHAR && str[i] != ';'))
	{
		if (str[i] == SEPARATOR_CHAR)
		{
			nb_separator++;
			smth = 0;
		}
		if (ft_strchr(LABEL_CHARS, str[i]))
			smth++;
		i++;
	}
	if (smth == 0)
		return (-100);
	return (nb_separator + 1);
}

int		ft_take_instruction_and_nb_arg(char *str, int *i, t_chain *b)
{
	int nb_arg;
	int j;

	j = 0;
	if (str[*i] == '\n')
		*i = *i + 1;
	while (str[*i] == ' ' || str[*i] == '\t')
		*i = *i + 1;
	j = *i;
	while (str[*i] && str[*i] >= 'a' && str[*i] <= 'z')
		*i = *i + 1;
	b->content = ft_strnmdup(str, j, *i);
	b->category = ft_strdup("INSTRUCTION");
	if (!(ft_check_if_instruction(b)))
		ft_is_an_error(str, *i);
	while (str[*i] == ' ' || str[*i] == '\t')
		*i = *i + 1;
	nb_arg = ft_take_nb_argument(str, *i);
	if (nb_arg != op_tab[b->nb_op_tab].nb_args)
	{
		ft_putendl("Wrong number of argument");
		ft_is_an_error(str, *i);
	}
	return (nb_arg);
}

int		ft_put_line_in_block(t_chain *b, int *i, char *str)
{
	int ok;
	int	nb_arg;
	int clone;

	nb_arg = ft_take_instruction_and_nb_arg(str, i, b);
	if ((b->nb_op_tab == 2 || b->nb_op_tab == 3 || b->nb_op_tab == 4 ||
b->nb_op_tab == 16 || b->nb_op_tab == 10) && !ft_is_lib(str, *i))
		ft_is_an_error(str, *i);
	if (!(b->next = ft_memalloc(sizeof(t_chain))))
		exit(0);
	b = b->next;
	clone = nb_arg;
	while (nb_arg)
	{
		if (!(ok = ft_complete_content(b, str, i)) && !(nb_arg - 1))
			break ;
		else if (!ok)
			ft_is_an_error(str, *i);
		if (!str[*i])
			break ;
		b = ft_inc(i, &nb_arg, b);
	}
	if (!b->content)
		free(b);
	return (clone);
}
