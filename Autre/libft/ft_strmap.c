/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:12:07 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/15 13:54:15 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char			*ft_strmap(char const *s, char (*f)(char))
{
	int		count;
	char	*newstr;

	count = 0;
	newstr = NULL;
	if (s != NULL && f != NULL)
	{
		if ((newstr = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
			return (NULL);
		while (s[count])
		{
			newstr[count] = f(s[count]);
			count++;
		}
		newstr[count] = '\0';
	}
	return (newstr);
}
