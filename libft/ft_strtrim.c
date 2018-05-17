/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:50:15 by alecott           #+#    #+#             */
/*   Updated: 2017/11/14 16:57:56 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (s == NULL)
		return (NULL);
	start = 0;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	end = ft_strlen(s);
	while ((s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')\
			&& end > 1)
		end--;
	if (end < start)
		end = start;
	str = (char*)ft_memalloc(end - start + 1);
	if (str == NULL)
		return (NULL);
	str[end - start] = '\0';
	str = ft_memcpy(str, s + start, end - start);
	return (str);
}
