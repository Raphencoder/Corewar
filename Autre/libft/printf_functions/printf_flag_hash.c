/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_hash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:29:49 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/22 18:49:57 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	printf_flag_hash(t_plist *list)
{
	char	*temp;

	temp = NULL;
	if (ft_strchr(list->flag, '#') || list->type == 'p')
	{
		if (ft_strchr(list->flag, '#') && list->type == 'o')
			temp = ft_strjoin("0", list->arg);
		if ((ft_strchr(list->flag, '#') &&
				list->type == 'x') || list->type == 'p')
			temp = ft_strjoin("0x", list->arg);
		else if (ft_strchr(list->flag, '#') && list->type == 'X')
			temp = ft_strjoin("0X", list->arg);
		free(list->arg);
		list->arg = temp;
	}
}
