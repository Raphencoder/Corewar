/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:43:57 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/21 16:31:59 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	unsigned int	count;
	char			*str;

	count = 0;
	if ((str = (char*)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	while (count < size + 1)
	{
		str[count] = '\0';
		count++;
	}
	return (str);
}

wchar_t	*ft_wstrnew(size_t size)
{
	unsigned int	count;
	wchar_t			*str;

	count = 0;
	if ((str = (wchar_t*)malloc(sizeof(wchar_t) * (size + 1))) == NULL)
		return (NULL);
	while (count < size + 1)
	{
		str[count] = '\0';
		count++;
	}
	return (str);
}
