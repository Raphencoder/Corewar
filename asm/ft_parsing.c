/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:05:57 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/22 13:09:57 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/asm.h"

int		ft_complete_name(char *str, int i, header_t *header)
{
	int j;

	j = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] != 34)
		return (-1);
	i++;
	while (str[i])
	{
		if (str[i] == 34)
			break ;
		header->prog_name[j] = str[i];
		j++;
		i++;
	}
	if (str[i] != 34)
		return (-1);
	header->prog_name[j] = '\0';
	return (i);
}


int		ft_complete_comment(char *str, int i, header_t *header)
{
	int j;

	j = 0;
	while (str[i] <= 32)
		i++;
	if (str[i] != 34)
		return (-1);
	i++;
	while (str[i])
	{
		if (str[i] == 34)
			break ;
		header->comment[j] = str[i];
		j++;
		i++;
	}
	if (str[i] != 34)
		return (-1);
	header->comment[j] = '\0';
	return (i);
}

int		ft_get_comment_then_name(header_t *header, char *str, int i)
{
	char	*tmp;
	int		j;

	j = ft_complete_comment(str, i + 8, header);
	if (j == -1)
		ft_is_an_error(str, i);
	i = j + 1;
	if (str[i] != '.' && str[i] != '#' && str[i] > 32)
		ft_is_an_error(str, i);
	ft_pass_comment(str, &i);
	tmp = ft_strnmdup(str, i, i + 5);
	if (!ft_strequ(NAME_CMD_STRING, tmp))
		ft_is_an_error(str, i + 5);
	if (!(j = ft_complete_name(str, i + 5, header)))
		ft_is_an_error(str, i);
	return (j);
}

int		ft_get_name_then_comment(header_t *header, char *str, int i)
{
	char	*tmp;
	int		j;

	j = ft_complete_name(str, i + 5, header);
	if (j == -1)
		ft_is_an_error(str, i);
	i = j + 1;
	if (str[i] != '.' && str[i] != '#' && str[i] > 32)
		ft_is_an_error(str, i);
	ft_pass_comment(str, &i);
	tmp = ft_strnmdup(str, i, i + 8);
	if (!ft_strequ(COMMENT_CMD_STRING, tmp))
		ft_is_an_error(str, i);
	if (!(j = ft_complete_comment(str, i + 8, header)))
		ft_is_an_error(str, i);
	return (j);
}

void	ft_parsing(char *str, header_t *header)
{
	int		i;
	int		j;
	char	*tmp;
	char	*tmpp;

	i = 0;
	j = 0;
	if (str[i] == '#')
		ft_pass_comment(str, &i);
	tmp = ft_strnmdup(str, i, i + 5);
	tmpp = ft_strnmdup(str, i, i + 8);
	if (!ft_strequ(NAME_CMD_STRING, tmp) && !ft_strequ(COMMENT_CMD_STRING, tmpp))
	{
		if (ft_strequ(NAME_CMD_STRING,tmp))
			ft_is_an_error(str, ft_strlen(tmpp));
		ft_is_an_error(str, ft_strlen(tmp));
	}	
	if (ft_strequ(NAME_CMD_STRING, tmp))
		j = ft_get_name_then_comment(header, str, i);
	else if (ft_strequ(COMMENT_CMD_STRING, tmpp))
		j = ft_get_comment_then_name(header, str, i);
	else
		ft_is_an_error(str, i);
	ft_get_in_chain(str, j);
	ft_putstr("le name est : ");
	ft_putendl(header->prog_name);
	ft_putendl("fin");
	ft_putstr("le comment est : ");
	ft_putendl(header->comment);
	ft_putendl("fin");
}
