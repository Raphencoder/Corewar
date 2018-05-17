/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 12:59:22 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/02 13:05:41 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_copy_tab(char **tab)
{
	int		i;
	char	**final;

	i = 0;
	while (tab[i])
		i++;
	final = (char**)ft_memalloc(sizeof(char*) * (i + 1));
	i = 0;
	while (tab[i])
	{
		final[i] = ft_strdup(tab[i]);
		i++;
	}
	return (final);
}
