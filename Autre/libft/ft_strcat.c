/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:38:47 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/21 16:55:24 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	if (ft_strlen(s1))
	{
		while (s1[count] != '\0')
			count++;
	}
	while (s2[count2] != '\0')
	{
		s1[count] = s2[count2];
		count++;
		count2++;
	}
	s1[count] = '\0';
	return (s1);
}

wchar_t	*ft_wstrcat(wchar_t *s1, const wchar_t *s2)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	if (ft_wstrlen(s1))
	{
		while (s1[count] != '\0')
			count++;
	}
	while (s2[count2] != '\0')
	{
		s1[count] = s2[count2];
		count++;
		count2++;
	}
	s1[count] = '\0';
	return (s1);
}
