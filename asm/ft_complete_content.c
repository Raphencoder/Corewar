/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_complete_content.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 15:05:32 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/30 11:23:31 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int		ft_check_if_error(char *str, int *i)
{
	int nb;

	nb = 0;
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		*i = *i + 1;
	if (str[*i] == SEPARATOR_CHAR)
		*i = *i + 1;
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		*i = *i + 1;
	if (str[*i] == 'r' && !(nb = ft_atoi(str + *i + 1)))
		ft_is_an_error(str, *i);
	if (nb > 99)
		ft_is_an_error(str, *i);
	if (str[*i] == ';' || str[*i] == COMMENT_CHAR)
	{
		ft_pass_comment(str, i);
		return (0);
	}
	if (!ft_strchr(LABEL_CHARS, str[*i]) && str[*i] != DIRECT_CHAR &&
			str[*i] != LABEL_CHAR && str[*i] != '-')
		ft_is_an_error(str, *i);
	return (1);
}

void	ft_check_if_direct(char *str, int *i, int *direct, int *label)
{
	if (*direct && !ft_isdigit(str[*i]))
		ft_is_an_error(str, *i);
	if (str[*i] == DIRECT_CHAR && (ft_isdigit(str[*i + 1])))
		*direct = *direct + 1;
	else if (str[*i] == DIRECT_CHAR && str[*i + 1] == '-')
	{
		*direct = *direct + 1;
		*i = *i + 1;
	}
	else if (str[*i] == DIRECT_CHAR && str[*i + 1] == LABEL_CHAR)
		*label = *label + 1;
	else if (str[*i] == DIRECT_CHAR)
		ft_is_an_error(str, *i + 1);
	if (*direct > 1 || *label > 1)
		ft_is_an_error(str, *i);
	*i = *i + 1;
}

int		ft_complete_content(t_chain *block, char *str, int *i)
{
	int j;
	int direct;
	int label;

	direct = 0;
	label = 0;
	j = 0;
	if (!ft_check_if_error(str, i))
		return (0);
	j = *i;
	while (str[*i] && str[*i] > 32 &&
			(str[*i] != SEPARATOR_CHAR && str[*i] != ';'))
		ft_check_if_direct(str, i, &direct, &label);
	block->content = ft_strnmdup(str, j, *i);
	block->category = "ARG";
	return (1);
}
