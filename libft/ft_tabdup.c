/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:17:57 by alecott           #+#    #+#             */
/*   Updated: 2018/02/28 11:16:30 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabdup(char **tab)
{
	int		i;
	char	**ret;

	i = 0;
	if ((ret = (char **)malloc(sizeof(char *) * (ft_tablen(tab) + 1))) == NULL)
		return (NULL);
	while (tab[i])
	{
		ret[i] = tab[i];
		i++;
	}
	tab[i] = NULL;
	return (ret);
}
