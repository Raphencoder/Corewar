/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_opti_allpaths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 08:50:08 by alecott           #+#    #+#             */
/*   Updated: 2018/05/02 12:52:18 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnmdup(char *str, int start, int end)
{
	char	*clone;
	int		i;

	i = 0;
	if ((clone = (char*)ft_memalloc(sizeof(char) * (end - start + 1))) == 0)
		return (0);
	while (start < end)
	{
		clone[i] = str[start];
		start++;
		i++;
	}
	return (clone);
}
