/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 16:52:40 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/22 17:13:40 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#include "../libft/libft.h"

void ft_verify_label(char *str, int j, t_chain *block)
{
	int		i;
	int		ok;
	char	*tmp;

	i = 0;
	ok = 0;
	(void)block;
	while (str[j])
	{
		if (str[j] == DIRECT_CHAR && str[j + 1] == LABEL_CHAR)
		{
			i = j + 2;
			while (str[j] && (str[j] > 32 && str[j] != SEPARATOR_CHAR))
				j++;
			tmp = ft_strnmdup(str, i, j);
			while (block->next)
			{
				if (ft_strequ(block->category, "LABEL"))
						ok = 1;
				block = block->next;
			}
			if (!ok)
			{
				ft_putstr("Sorry but the label you put doesn't exist\n");
				ft_putstr(tmp);
				ft_is_an_error(str, i); 
			}
		}
		j++;
	}
}
