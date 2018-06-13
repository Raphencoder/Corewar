/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:42:43 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/12 12:47:01 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t count;

	count = 0;
	while (count < n)
	{
		((unsigned char*)dst)[count] = ((unsigned char*)src)[count];
		count++;
	}
	return (dst);
}
