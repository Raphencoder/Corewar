/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:02:11 by alecott           #+#    #+#             */
/*   Updated: 2018/03/04 12:36:46 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabjoin(char **tab1, char **tab2)
{
	int		i;
	int		j;
	char	**ret;

	i = 0;
	j = 0;
	if (tab1 == NULL || tab2 == NULL)
		return (NULL);
	if ((ret = (char **)ft_memalloc(sizeof(char *) *
			(ft_tablen(tab1) + ft_tablen(tab2) + 1))) == NULL)
		return (NULL);
	while (tab1[i])
	{
		ret[i] = ft_strdup(tab1[i]);
		i++;
	}
	while (tab2[j])
	{
		ret[i + j] = ft_strdup(tab2[j]);
		j++;
	}
	ret[i + j] = NULL;
	return (ret);
}
