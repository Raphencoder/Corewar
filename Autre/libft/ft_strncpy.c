/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 11:32:48 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/14 12:54:41 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	unsigned int count;

	count = 0;
	while (src[count] != '\0' && count < len)
	{
		dst[count] = src[count];
		count++;
	}
	while (count < len)
	{
		dst[count] = '\0';
		count++;
	}
	return (dst);
}
