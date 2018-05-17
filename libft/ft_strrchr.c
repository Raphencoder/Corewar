/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:05:54 by alecott           #+#    #+#             */
/*   Updated: 2017/11/10 10:44:39 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = ft_strdup(s);
	i = ft_strlen(s);
	while (i >= 0 && str[i] != c)
		i--;
	if (str[i] == c)
		return ((char*)s + i);
	return (NULL);
}
