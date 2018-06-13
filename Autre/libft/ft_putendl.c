/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:19:19 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/15 15:07:42 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putendl(char const *s)
{
	int count;

	count = 0;
	if (s)
	{
		while (s[count] != '\0')
		{
			ft_putchar(s[count]);
			count++;
		}
		ft_putchar('\n');
	}
}
