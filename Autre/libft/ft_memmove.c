/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmove.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:57:36 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/14 11:53:39 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			count;
	unsigned char	*dsts;
	unsigned char	*srcs;

	count = 0;
	dsts = (unsigned char*)dst;
	srcs = (unsigned char*)src;
	if (src < dst)
	{
		len--;
		while ((int)len >= 0)
		{
			dsts[len] = srcs[len];
			len--;
		}
	}
	else
		while (count < len)
		{
			dsts[count] = srcs[count];
			count++;
		}
	return (dst);
}
