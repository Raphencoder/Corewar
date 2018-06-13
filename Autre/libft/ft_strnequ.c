/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:53:43 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/15 20:09:54 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	unsigned int count;

	count = 0;
	if (n == 0)
		return (1);
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[count] == s2[count]
				&& s1[count] && s2[count] && count < n - 1)
			count++;
		if ((s1[count] - s2[count]) == 0)
			return (1);
	}
	return (0);
}
