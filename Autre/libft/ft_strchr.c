/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:41:18 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/03 12:47:30 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	int		count;

	count = 0;
	while (s[count] && s[count] != c)
		count++;
	if (s[count] && s[count] == c)
		return (&((char*)s)[count]);
	else
		return (NULL);
}
