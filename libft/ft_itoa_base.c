/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/23 13:20:35 by alecott           #+#    #+#             */
/*   Updated: 2018/06/28 13:11:33 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nbr, int base)
{
	int		n;

	n = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		n++;
		nbr = nbr / base;
	}
	return (n);
}

char		*ft_itoa_base(int nbr, int base)
{
	char	*str;
	int		len;

	len = ft_len(nbr, base);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (0);
	str[len] = '\0';
	while (len >= 0)
	{
		len--;
		if (nbr % base > 9)
			str[len] = nbr % base + 87;
		else
			str[len] = nbr % base + '0';
		nbr = nbr / base;
	}
	return (str);
}
