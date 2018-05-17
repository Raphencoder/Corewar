/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 12:16:18 by alecott           #+#    #+#             */
/*   Updated: 2018/02/27 15:27:14 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_tabstr(char **tab, const char *s, int mode)
{
	int		i;

	i = 0;
	if (mode == 1)
	{
		while (tab[i])
		{
			if (ft_strstr(tab[i], s))
				return (1);
			i++;
		}
	}
	else if (mode == 2)
	{
		while (tab[i])
		{
			if (ft_strstr(s, tab[i]))
			{
				return (1);
			}
			i++;
		}
	}
	return (0);
}
