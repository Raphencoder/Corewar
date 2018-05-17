/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:04:26 by alecott           #+#    #+#             */
/*   Updated: 2017/11/10 15:22:32 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(const char *s)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(s) - 1;
	if (s == NULL)
		return (NULL);
	str = (char*)malloc(sizeof(*str) * (ft_strlen(s) + 1));
	if (str == NULL)
		return (NULL);
	while (j >= 0)
	{
		str[i] = s[j];
		i++;
		j--;
	}
	str[i] = '\0';
	return (str);
}
