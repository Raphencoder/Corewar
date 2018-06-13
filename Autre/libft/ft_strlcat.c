/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:50:14 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/14 14:42:26 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int count;
	unsigned int count2;
	unsigned int to_copy;

	count = ft_strlen(dst);
	count2 = 0;
	to_copy = ft_strlen(src) + (size <= count ? size : count);
	if (size == 0)
		return (to_copy);
	while (src[count2] != '\0' && count < (size - 1))
		dst[count++] = src[count2++];
	dst[count] = '\0';
	return (to_copy);
}
