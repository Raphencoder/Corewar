/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 10:53:29 by alecott           #+#    #+#             */
/*   Updated: 2017/11/14 17:04:33 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (n == 0)
		return (ft_strlen((char*)src));
	while (dest[i] && i < n)
		i++;
	j = i;
	while (src[i - j] && i < n - 1)
	{
		dest[i] = src[i - j];
		i++;
	}
	if (j < n)
		dest[i] = '\0';
	return (j + ft_strlen((char*)src));
}
