/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 14:37:15 by alecott           #+#    #+#             */
/*   Updated: 2017/11/15 09:01:41 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	j;

	j = 0;
	if (s == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (j < len)
	{
		str[j] = s[start + j];
		j++;
	}
	str[j] = '\0';
	return (str);
}
