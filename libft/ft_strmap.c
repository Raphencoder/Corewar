/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 13:51:45 by alecott           #+#    #+#             */
/*   Updated: 2017/11/14 11:45:14 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f((char)s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
