/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:38:44 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/15 19:42:09 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	count;
	char			*newstr;

	count = 0;
	newstr = NULL;
	if (s && f)
	{
		if ((newstr = ft_strnew(ft_strlen(s))) == NULL)
			return (NULL);
		while (s[count])
		{
			newstr[count] = f(count, s[count]);
			count++;
		}
		newstr[count] = '\0';
	}
	return (newstr);
}
