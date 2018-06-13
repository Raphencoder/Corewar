/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:17:11 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/09 12:33:21 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	while (s1[count] != '\0')
		count++;
	while (s2[count2] != '\0' && n > 0)
	{
		s1[count] = s2[count2];
		count++;
		count2++;
		n--;
	}
	s1[count] = '\0';
	return (s1);
}
