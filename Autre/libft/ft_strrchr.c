/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:46:52 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/14 17:58:04 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int				count;
	int				check_find;
	unsigned char	*ptr;
	unsigned char	cha;
	unsigned char	*str;

	count = 0;
	cha = (unsigned char)c;
	str = (unsigned char*)s;
	check_find = 0;
	while (str[count])
	{
		if (s[count] == cha)
		{
			ptr = &str[count];
			check_find = 1;
		}
		count++;
	}
	if (str[count] == '\0' && cha == '\0')
		return (&((char*)str)[count]);
	if (count == 0 || check_find == 0)
		return (NULL);
	return ((char*)ptr);
}
