/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:27:18 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/22 18:48:09 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <string.h>

size_t	ft_strlen(const char *s)
{
	unsigned int count;

	count = 0;
	while (s && s[count] != '\0')
		count++;
	return (count);
}

int		ft_getbyteslength(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c <= 2047)
		return (2);
	else if (c <= 65535)
		return (3);
	else if (c <= 2097151)
		return (4);
	else if (c <= 67108863)
		return (5);
	else if (c <= 2147483647)
		return (6);
	return (0);
}

size_t	ft_wstrlen(const wchar_t *s)
{
	size_t	count;
	size_t	length;

	count = 0;
	length = 0;
	while (s && s[count] != '\0')
	{
		length += ft_getbyteslength(s[count]);
		count++;
	}
	return (length);
}
