/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:01:01 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/16 15:15:46 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			count;
	unsigned char	*srcc;
	unsigned char	*dstc;

	count = 0;
	srcc = (unsigned char*)src;
	dstc = (unsigned char*)dst;
	if (n)
	{
		while (count < n)
		{
			dstc[count] = srcc[count];
			if (srcc[count] == (unsigned char)c)
				return (&dstc[count + 1]);
			count++;
		}
	}
	return (NULL);
}
