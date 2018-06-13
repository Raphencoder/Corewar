/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:59:28 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/15 13:52:07 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int count;

	count = 0;
	if (s != NULL && f != NULL)
	{
		while (s[count] != '\0')
		{
			f(count, &s[count]);
			count++;
		}
	}
}
