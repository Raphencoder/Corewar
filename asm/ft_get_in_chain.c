/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_get_in_chain.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:04:44 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/18 13:30:17 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../op.h"
#include <stdio.h>


void	ft_is_an_error(char *str, int i);
void    ft_pass_comment(char *str, int *i);

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

void	ft_complete_content(t_chain *block, char *str, int *i)
{
	int	j;
	int	direct;

	direct = 0;
	ft_putendl("IN complete_content");
	j = 0;
	while (str[*i] == ' ' || str[*i] == '\t')
		*i = *i + 1;
	j = *i;
	while (str[*i] > 32 && str[*i] != SEPARATOR_CHAR)
	{
		ft_putstr("Start ");
		if (str[*i] == DIRECT_CHAR && (str[*i + 1] != LABEL_CHAR &&
!ft_isnumber(str + (*i + 1))))
		{
			if (direct)
				ft_is_an_error(str, *i);
			ft_putendl("aww nooon");
			ft_putnbr(ft_isnumber(str + *i));
			ft_putchar('T');
			ft_putchar('\n');
			ft_putendl(str + *i);
			ft_is_an_error(str, *i);
			direct++;
		}
		if (direct > 1)
			ft_is_an_error(str, *i);
		*i = *i + 1;
	}
	block->content = ft_strnmdup(str, j, *i);
	block->category = "INSTRUCTION";
	ft_putendl("finish one block");
	ft_putstr("block->contetn = ");	
	ft_putendl(block->content);
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

	ft_putendl("IN put line in block");
	while (str[*i] == ' ' || str[*i] == '\t')
		*i = *i + 1;
	j = *i;
	while (str[*i] >= 'a' && str[*i] <= 'z')
		*i = *i + 1;
	block->content = ft_strnmdup(str, j, *i);
	block->category = "INSTRUCTION";
	ft_putstr("block->content = ");
	ft_putendl(block->content);
//	if (!(ft_check_if_instruction(block)))
//		ft_is_an_error(str, j);
	while (str[*i] == ' ' || str[*i] == '\t')
		*i = *i + 1;
	nb_arg = ft_take_nb_argument(str, *i);
	ft_putstr("nb_arg = ");
	ft_putnbr(nb_arg);
	ft_putchar('\n');
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
	new = block->next;
	new = ft_memalloc(sizeof(t_chain));
	while (nb_arg)
	{
		ft_complete_content(new, str, i);
		*i = *i + 1;
		nb_arg--;
		new = new->next;
		new = ft_memalloc(sizeof(t_chain));
	}
	return (new);
}


t_chain	*ft_put_label_in_block(t_chain *block, int i, char *str, int j)
{
	int k;

	ft_putendl("IN put label in block");
	k = 0;
	block->category = "LABEL";
	block->content = ft_strnmdup(str, i, j + 1);
	ft_putstr("label = ");
	ft_putendl(block->content);
	return (block->next);
}

t_chain	*ft_put_in_block(t_chain *block, int *j, char *str)
{
	int i;
	int	pos;
	t_chain *new;

	i = *j;
	ft_putendl("IN put in block");
	while (str[*j] != '\n')
	{
		if (str[*j] == LABEL_CHAR && str[*j - 1] != DIRECT_CHAR)
		{
			new = ft_put_label_in_block(block, i, str, *j);
			new = ft_memalloc(sizeof(t_chain));
			return (new);
		}
		*j = *j + 1;
	}
	new = ft_put_line_in_block(block, &i, str);
	new = ft_memalloc(sizeof(t_chain));
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
	start = &block;
	while (str[j])
	{
		if (str[j] == '\n')
			block->nb_lines++;
		else if (str[j] == '#')
			ft_pass_comment(str, &j);
		else if (str[j] == ' ' || str[j] == '\t')
		{
			ft_pass_space(str, &j);
			continue ;
		}
		else if ((!ft_strchr(LABEL_CHARS, str[j])) && str[j] != DIRECT_CHAR)
			ft_is_an_error(str, j);
		else
			block = ft_put_in_block(block, &j, str);
		j++;
		ft_putendl("tour");
	}
}
