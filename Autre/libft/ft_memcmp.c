/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:00:33 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/15 17:12:01 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	temp;
	unsigned char	temp2;

	if (n == 0)
		return (0);
	count = 0;
	temp = ((unsigned char*)s1)[count];
	temp2 = ((unsigned char*)s2)[count];
	while ((count < n) && (temp == temp2))
	{
		temp = ((unsigned char*)s1)[count];
		temp2 = ((unsigned char*)s2)[count];
		count++;
	}
	return (temp - temp2);
}
