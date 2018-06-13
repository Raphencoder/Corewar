/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:43:06 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/15 19:57:25 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t count;

	count = 0;
	if (n == 0)
		return (0);
	while (s1[count] == s2[count] && s1[count] & s2[count] && count < (n - 1))
		count++;
	return (((unsigned char*)s1)[count] - ((unsigned char*)s2)[count]);
}
