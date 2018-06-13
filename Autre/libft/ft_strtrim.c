/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:36:04 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/17 13:38:11 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdlib.h>

char			*ft_strtrim(char const *s)
{
	int		begin;
	int		length;
	int		count3;
	char	*newstr;

	begin = 0;
	count3 = 0;
	newstr = NULL;
	if (s == NULL)
		return (NULL);
	length = ft_strlen(s) - 1;
	while (ft_ispace(s[begin]))
		begin++;
	while (ft_ispace(s[length]) && length >= begin)
		length--;
	if ((newstr = (char*)malloc(sizeof(char) * (length - begin + 2))) == NULL)
		return (NULL);
	while (begin <= length && length > 0)
		newstr[count3++] = s[begin++];
	newstr[count3] = '\0';
	return (newstr);
}
