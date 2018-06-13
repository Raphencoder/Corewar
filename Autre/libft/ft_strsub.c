/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:57:19 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/15 14:32:40 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*strnew;
	unsigned int	count;

	count = 0;
	strnew = NULL;
	if (s != NULL)
	{
		if ((strnew = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
		while (count < len)
		{
			strnew[count] = s[count + start];
			count++;
		}
		strnew[count] = '\0';
	}
	return (strnew);
}
