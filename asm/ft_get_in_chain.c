/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_in_chain.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:04:44 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/24 10:42:53 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_take_nb_argument(char *str, int i)
{
	int nb_separator;

	nb_separator = 0;
	while (str[i] && (str[i] != '\n' && str[i] != COMMENT_CHAR && str[i] != ';'))
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

int		ft_complete_content(t_chain *block, char *str, int *i)
{
	int	j;
	int	direct;

	direct = 0;
	j = 0;
	while (str[*i] == ' ' || str[*i] == '\t')
		*i = *i + 1;
	if (str[*i] == SEPARATOR_CHAR)
		*i = *i + 1;
	while (str[*i] == ' ' || str[*i] == '\t')
		*i = *i + 1;
	if (str[*i] == 'r' && ft_isdigit(str[*i + 3]))
		ft_is_an_error(str, *i);
	if (str[*i] == ';' || str[*i] == COMMENT_CHAR){
		ft_pass_comment(str, i);
		return (0);}
	if (!ft_strchr(LABEL_CHARS, str[*i]) && str[*i] != DIRECT_CHAR && str[*i] != '-')
		ft_is_an_error(str, *i);
	j = *i;
	while (str[*i] > 32 && (str[*i] != SEPARATOR_CHAR && str[*i] != ';'))
	{
		if (str[*i] == DIRECT_CHAR)
			direct++;
		if (direct > 1)
			ft_is_an_error(str, *i);
		*i = *i + 1;
	}
	block->content = ft_strnmdup(str, j, *i);
	block->category = "ARG";
	return (1);
}


int	ft_check_if_instruction(t_chain *block)
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

int		ft_put_line_in_block(t_chain *block, int *i, char *str)
{
	int	nb_arg;
	int j;
	int clone;

	nb_arg = 0;
	if (str[*i] == '\n')
		*i = *i + 1;
	while (str[*i] == ' ' || str[*i] == '\t')
		*i = *i + 1;
	j = *i;
	while (str[*i] && str[*i] >= 'a' && str[*i] <= 'z')
		*i = *i + 1;
	block->content = ft_strnmdup(str, j, *i);
	block->category = "INSTRUCTION";
	if (!(ft_check_if_instruction(block)))
		ft_is_an_error(str, *i);
	while (str[*i] == ' ' || str[*i] == '\t')
		*i = *i + 1;	
	nb_arg = ft_take_nb_argument(str, *i);
	if (nb_arg != op_tab[block->nb_op_tab].nb_args)
	{
		ft_putendl("wrong number of argument");
		ft_is_an_error(str, *i);
	}
	else if ((block->nb_op_tab == 2 || block->nb_op_tab == 3 || 
block->nb_op_tab == 4 || block->nb_op_tab == 16 ||
block->nb_op_tab == 10) && !ft_is_lib(str, *i))
		ft_is_an_error(str, *i);
	block->next = ft_memalloc(sizeof(t_chain));
	block = block->next;
	clone = nb_arg;
	while (nb_arg)
	{
		if (!(ft_complete_content(block, str, i)))
			continue ;
		if (!str[*i])
			break ;
		*i = *i + 1;
		nb_arg--;
		block->next = ft_memalloc(sizeof(t_chain));
		block = block->next;
	}
	return (clone);
}


void	ft_put_label_in_block(t_chain *block, int i, char *str, int j)
{
	int k;

	k = 0;
	block->category = "LABEL";
	if (!ft_strchr(LABEL_CHARS, str[i]))
		i++;
	block->content = ft_strnmdup(str, i, j + 1);
	return ;
}

int		ft_put_in_block(t_chain *block, int *j, char *str)
{
	int i;
	int nb_arg;

	i = *j - 1;
	nb_arg = 0;
	while (str[*j] && str[*j] != '\n')
	{
		if (str[*j] == LABEL_CHAR && str[*j - 1] != DIRECT_CHAR)
		{
			ft_put_label_in_block(block, i, str, *j);
			return (0);
		}
		*j = *j + 1;
	}
	nb_arg = ft_put_line_in_block(block, &i, str);
	*j = i;
	return (nb_arg);
}

void	ft_pass_space(char *str, int *j)
{
	int i;

	i = 0;
	while (str[*j] && str[*j] < 32)
	{
		if (str[*j] == '\n')
			return ;
		*j = *j + 1;
	}
}

t_chain	*ft_get_in_chain(char *str, int j)
{
	t_chain		*block;
	void		*start;
	int			nb_arg;
	int			i;

	nb_arg = 0;
	j++;
	block = ft_memalloc(sizeof(t_chain));
	block->next = 0;
	start = block;
	i = 0;
	while (str[j])
	{
		if (str[j] == '\n')
			block->nb_lines++;
		else if (str[j] == '#' || str[j] == ';')
		{
			ft_pass_comment(str, &j);
			continue ;
		}
		else if (str[j] == ' ' || str[j] == '\t')
		{
			ft_pass_space(str, &j);
			continue ;
		}
		else if ((!ft_strchr(LABEL_CHARS, str[j])) && str[j] != DIRECT_CHAR)
			ft_is_an_error(str, j);
		else
		{
			nb_arg = ft_put_in_block(block, &j, str);
			while (nb_arg)
			{
				block = block->next;
				nb_arg--;
			}
			block->next = ft_memalloc(sizeof(t_chain));
			block = block->next;
			block->content = ft_strdup("\n");
			block->category = "ENDL";
			block->next = ft_memalloc(sizeof(t_chain));
			block = block->next;
		}
		if (!str[j])
			break ;
		if (str[j] == '#' || str[j] == ';')
		{
			ft_pass_comment(str, &j);
			continue ;
		}
		j++;
	}
	block = start;
	return (block);
	while (block->next)
	{
		ft_putstr(" |>");
		ft_putstr(block->content);
		ft_putstr("<| ");
		block = block->next;
	}
	block = start;
}
