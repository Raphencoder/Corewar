/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:40:21 by alecott           #+#    #+#             */
/*   Updated: 2017/11/15 08:59:36 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
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
		if (s1[i] == s2[0] && ft_strlen(s2) <= n && n >= (ft_strlen(s2) + i))
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
