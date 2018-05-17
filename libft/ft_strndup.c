/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <rkrief@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 13:06:59 by rkrief            #+#    #+#             */
/*   Updated: 2018/04/20 12:28:58 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s1, size_t n)
{
	char	*clone;
	int		j;

	if (((clone = (char*)malloc(sizeof(char) * ft_strlen(s1) + 1)) == 0))
		return (NULL);
	j = 0;
	while (s1[j] && n > 0)
	{
		clone[j] = s1[j];
		j++;
		n--;
	}
	clone[j] = '\0';
	return (clone);
}
