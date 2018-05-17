/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_get_in_chain.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:04:44 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/17 20:20:19 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem-in/libft/libft.h"
#include "../includes/op.h"
#include <stdio.h>


void	ft_is_an_error(char *str, int i);

void	ft_pass_comment1(char *str, int *i)
{
	while (str[*i])
	{
		while (str[*i] && str[*i] != '\n')
			*i = *i + 1;
		if (str[*i + 1] && (str[*i + 1] != '#' && str[*i + 1] != '\n'))
		{
			*i = *i + 1;
			return ;
		}
		if (str[*i + 1])
			*i = *i + 1;
	}
}

int		ft_take_nb_argument(char *str, int i)
{
	int nb_separator;

	nb_separator = 0;
	while (str[i] != '\n')
	{
		if (str[i] == SEPARATOR_CHAR)
			nb_separator++;
		i++;
	}
	return (nb_separator + 1);
}

int		ft_is_lib(char *str, int i)
{
	if (str[i] != 'r')
		return (0);
	i++;
	if (ft_isdigit(str[i]) && (ft_isdigit(str[i + 1]) || str[i + 1] == ' ' ||
				str[i + 1] == '\t' || str[i + 1] == SEPARATOR_CHAR))
		return (1);
	return (0);
}

t_chain	*ft_complete_content(t_chain *block, char *str, int *i)
{
	int direct;
	int	j;
	t_chain *new;

	new = ft_memalloc(sizeof(t_chain));
	direct = 0;
	j = 0;
	while (str[*i] == ' ' || str[*i] == '\t')
		*i = *i + 1;
	while (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\n')
	{
		if (direct && (str[*i] != LABEL_CHAR || ft_atoi(str + *i)))
			ft_is_an_error(str, *i);
		if (str[*i] == DIRECT_CHAR)
			direct++;
		if (direct > 1)
			ft_is_an_error(str, *i);
		block->content[j++] = str[*i];
		*i = *i + 1;
	}
	block->category = "INSTRUCTION";
	ft_putendl("finish one block");
	ft_putendl(block->content);
	new = block->next;
	return (new);
}


//int	ft_check_if_instruction(t_chain *block)
/*{
	int i;

	i = 0;
	while (i < 16)
	{
		if (ft_strequ(op_tab[i][0], block->content))
		{
			block->nb_op_tab = i;
			return (1);
		}
		i++;	
	}
	return (0);
}
*/
t_chain		*ft_put_line_in_block(t_chain *block, int *i, char *str)
{
	int	nb_arg;
	int j;
	t_chain *new;

	while (str[*i] == ' ' || str[*i] == '\t')
		*i = *i + 1;
	j = *i;
	while (str[*i] >= 'a' && str[*i] <= 'z')
	{
		block->content[j++] = str[*i];
		*i = *i + 1;
	}
//	if (!(ft_check_if_instruction(block)))
//		ft_is_an_error(str, j);
	while (str[*i] == ' ' || str[*i] == '\t')
		*i = *i + 1;
	nb_arg = ft_take_nb_argument(str, *i);
//	if (nb_arg != op_tab[block->nb_op_tab][1])
//	{
//		ft_putendl("wrong number of argument");
//		ft_is_an_error(str, *i);
//	}
//	if ((op_tab[block->nb_op_tab][2] == 1) && 
//			(op_tab[block->nb_op_tab][3] == T_DIR && str[*i] != DIRECT_CHAR))
//		ft_is_an_error(str, *i);
//	else if ((block->nb_op_tab == 2 || block->nb_op_tab == 3 || block->nb_op_tab
//				== 4 || block->nb_op_tab == 16 || block->nb_op_tab == 10) && ft_is_lib(str, *i))
//		ft_is_an_error(str, *i);
	while (nb_arg)
	{
		new = ft_complete_content(block, str, i);
		*i = *i + 1;
		nb_arg--;
	}
	return (new);
}


t_chain	*ft_put_label_in_block(t_chain *block, int *i, char *str, int j)
{
	int k;
	t_chain *new;

	
	ft_putendl("test");
	k = 0;
	block->category = "LABEL";
	block->content = ft_strnmdup(str, *i, j + 1);
	ft_putendl("test");
	new = ft_memalloc(sizeof(t_chain));
	new = block->next;
	return (new);
}

t_chain	*ft_put_in_block(t_chain *block, int *j, char *str)
{
	int i;
	int	pos;
	t_chain *new;

	i = *j;
	while (str[*j] != '\n')
	{
		if (str[*j] == LABEL_CHAR && str[*j - 1] != DIRECT_CHAR)
		{
			new = ft_put_label_in_block(block, &i, str, *j);
			ft_putendl("test");
			return (new);
		}
		*j = *j + 1;
	}
	new = ft_put_line_in_block(block, &i, str);
	*j = i;
	return (new);
}

void	ft_pass_space(char *str, int *j)
{
	int i;

	i = 0;
	while (str[*j] < 32)
	{
		if (str[*j] == '\n')
			return ;
		*j = *j + 1;
	}
}

void	ft_get_in_chain(char *str, int j)
{
	t_chain		*block;
	void		*start;

	j++;
	block = ft_memalloc(sizeof(t_chain));
	block->next = 0;
	start = block;
	ft_putendl("test");
	while (str[j])
	{
		if (str[j] == '\n')
			block->nb_lines++;
		else if (str[j] == '#')
			ft_pass_comment1(str, &j);
		else if (str[j] == ' ' || str[j] == '\t')
			ft_pass_space(str, &j);
		else if ((!ft_strchr(LABEL_CHARS, str[j])) && str[j] != DIRECT_CHAR)
			ft_is_an_error(str, j);
		else
			ft_put_in_block(block, &j, str);
		j++;
	}
}
