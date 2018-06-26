/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 16:05:57 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/04 16:57:08 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
		if (j > 128)
		{
			ft_putendl("Champion name too long (Max length 128)");
			exit (0);
		}
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
		if (j > 2048)
		{
			ft_putendl("Champion comment too long (Max length 2048)");
			exit (0);
		}
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

	j = ft_complete_comment(str, i + ft_strlen(COMMENT_CMD_STRING), header);
	if (j == -1)
		ft_is_an_error(str, i);
	i = j + 1;
	if (str[i] != NAME_CMD_STRING[0] && str[i] != COMMENT_CHAR &&
			str[i] != ';' && str[i] > 32)
		ft_is_an_error(str, i);
	while (str[i] <= 32)
		i++;
	if (str[i] == COMMENT_CHAR || str[i] == ';')
		ft_pass_comment(str, &i);
	else if (str[i] != NAME_CMD_STRING[0])
		ft_is_an_error(str, i);
	tmp = ft_strnmdup(str, i, i + ft_strlen(NAME_CMD_STRING));
	if (!ft_strequ(NAME_CMD_STRING, tmp))
		ft_is_an_error(str, i + ft_strlen(NAME_CMD_STRING));
	if (!(j = ft_complete_name(str, i + ft_strlen(NAME_CMD_STRING),
					header)))
		ft_is_an_error(str, i);
	ft_strdel(&tmp);
	return (j);
}

int		ft_get_name_then_comment(header_t *header, char *str, int i)
{
	char	*tmp;
	int		j;

	j = ft_complete_name(str, i + ft_strlen(NAME_CMD_STRING), header);
	if (j == -1)
		ft_is_an_error(str, i);
	i = j + 1;
	if (str[i] != COMMENT_CMD_STRING[0] && str[i] != COMMENT_CHAR &&
			str[i] != ';' && str[i] > 32)
		ft_is_an_error(str, i);
	while (str[i] <= 32)
		i++;
	if (str[i] == COMMENT_CHAR || str[i] == ';')
		ft_pass_comment(str, &i);
	else if (str[i] != NAME_CMD_STRING[0])
		ft_is_an_error(str, i);
	tmp = ft_strnmdup(str, i, i + ft_strlen(COMMENT_CMD_STRING));
	if (!ft_strequ(COMMENT_CMD_STRING, tmp))
		ft_is_an_error(str, i);
	if (!(j = ft_complete_comment(str, i + ft_strlen(COMMENT_CMD_STRING),
					header)))
		ft_is_an_error(str, i);
	ft_strdel(&tmp);
	return (j);
}

t_chain		*ft_parsing(char *str, header_t *header, char *str2)
{
	int		i;
	int		j;
	t_chain	*block;
	char	*tmp;
	char	*tmpp;

	i = 0;
	j = 0;
	if (!str || !str[i] || !ft_isascii(str[i]))
		ft_is_an_error(str, i);
	if (str[i] == COMMENT_CHAR || str[i] == ';')
		ft_pass_comment(str, &i);
	tmp = ft_strnmdup(str, i, i + ft_strlen(NAME_CMD_STRING));
	tmpp = ft_strnmdup(str, i, i + ft_strlen(COMMENT_CMD_STRING));
	if (!ft_strequ(NAME_CMD_STRING, tmp) &&
			!ft_strequ(COMMENT_CMD_STRING, tmpp))
		ft_is_an_error(str, ft_strlen(tmp));
	if (ft_strequ(NAME_CMD_STRING, tmp))
		j = ft_get_name_then_comment(header, str, i);
	else if (ft_strequ(COMMENT_CMD_STRING, tmpp))
		j = ft_get_comment_then_name(header, str, i);
	else
		ft_is_an_error(str, i);
	block = ft_get_in_chain(str, j);
	ft_verify_label(str, block);
	ft_nbr_link(block);
	ft_asm(str2, block, header);
	ft_strdel(&tmp);
	ft_strdel(&tmpp);
	return (block);
}
