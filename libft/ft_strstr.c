/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:26:27 by alecott           #+#    #+#             */
/*   Updated: 2018/02/25 12:15:49 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	int		y;

	i = 0;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[i])
	{
		j = 0;
		if (s1[i] == s2[0])
		{
			y = i;
			while (s1[y] == s2[j] && s2[j] && s1[y])
			{
				j++;
				y++;
			}
			if (s2[j] == '\0')
				return ((char*)s1 + i);
		}
		i++;
	}
	return (NULL);
}
