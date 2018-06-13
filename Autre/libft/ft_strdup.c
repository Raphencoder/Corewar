/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:58:13 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/21 17:06:33 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	int		count;
	int		length;
	char	*copy;

	count = 0;
	length = ft_strlen(s1);
	if (!(copy = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	while (count < length)
	{
		copy[count] = s1[count];
		count++;
	}
	copy[count] = '\0';
	return (copy);
}

wchar_t	*ft_wstrdup(const wchar_t *s1)
{
	int		count;
	int		length;
	wchar_t	*copy;

	count = 0;
	length = ft_wstrlen(s1);
	if (!(copy = (wchar_t*)malloc(sizeof(wchar_t) * (length + 1))))
		return (NULL);
	while (count < length)
	{
		copy[count] = s1[count];
		count++;
	}
	copy[count] = '\0';
	return (copy);
}

char	*ft_noleaks_strndup(char *s1, size_t n)
{
	int		count;
	int		length;
	char	*copy;

	count = 0;
	length = ft_strlen(s1) - n;
	if (!(copy = (char*)malloc(sizeof(char) * (length + 1 - n))))
		return (NULL);
	while (count < length)
	{
		copy[count] = s1[count + n];
		count++;
	}
	copy[count] = '\0';
	ft_memdel((void**)&s1);
	return (copy);
}
