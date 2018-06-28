/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_in_chain.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:04:44 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/28 13:22:51 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	ft_put_label_in_block(t_chain *block, int i, char *str, int j)
{
	block->category = ft_strdup("LABEL");
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
		if (str[*j] == COMMENT_CHAR)
			ft_pass_comment(str, j);
		if (str[*j] == LABEL_CHAR && (str[*j - 1] != DIRECT_CHAR &&
					ft_strchr(LABEL_CHARS, str[*j - 1])))
		{
			ft_put_label_in_block(block, i, str, *j);
			return (0);
		}
		if (str[*j] <= 32)
			break ;
		*j = *j + 1;
	}
	nb_arg = ft_put_line_in_block(block, &i, str);
	*j = i;
	return (nb_arg);
}

t_chain	*ft_else(t_chain *block, char *str, int *j)
{
	int	nb_arg;

	nb_arg = 0;
	nb_arg = ft_put_in_block(block, j, str);
	while (nb_arg)
	{
		block = block->next;
		nb_arg--;
	}
	if (!(block->next = ft_memalloc(sizeof(t_chain))))
		exit(0);
	block = block->next;
	block->content = ft_strdup("\n");
	block->category = ft_strdup("ENDL");
	if (!(block->next = ft_memalloc(sizeof(t_chain))))
		exit(0);
	block = block->next;
	return (block);
}

t_chain	*ft_begin(char *str, int *j, t_chain *block)
{
	if (str[*j] == '\n')
		block->nb_lines++;
	else if (str[*j] == COMMENT_CHAR || str[*j] == ';')
		ft_pass_comment(str, j);
	else if (str[*j] == ' ' || str[*j] == '\t')
		ft_pass_space(str, j);
	else if ((!ft_strchr(LABEL_CHARS, str[*j])) && str[*j] != DIRECT_CHAR)
		ft_is_an_error(str, *j);
	else
		block = ft_else(block, str, j);
	return (block);
}

t_chain	*ft_get_in_chain(char *str, int j)
{
	t_chain		*block;
	void		*start;

	j++;
	if (!(block = ft_memalloc(sizeof(t_chain))))
		exit(0);
	block->next = 0;
	start = block;
	while (str[j])
	{
		block = ft_begin(str, &j, block);
		if (!str[j])
			break ;
		if (str[j] == COMMENT_CHAR || str[j] == ';')
			ft_pass_comment(str, &j);
		j++;
	}

	block = start;
	return (block);
}
