/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:47:46 by alecott           #+#    #+#             */
/*   Updated: 2017/12/21 08:52:02 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int nbr)
{
	int		n;

	n = 0;
	if (nbr < 0)
		n++;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		n++;
		nbr = nbr / 10;
	}
	return (n);
}

char		*ft_itoa(int nbr)
{
	char	*str;
	int		len;

	len = ft_len(nbr);
	if (!(str = (char*)malloc(sizeof(*str) * (len + 1))))
		return (0);
	str[len] = '\0';
	if (nbr < 0)
		str[0] = '-';
	while (len >= 0)
	{
		len--;
		if (nbr < 0 && str[len] != '-')
			str[len] = ((nbr % 10) * -1) + '0';
		else if (str[len] != '-')
			str[len] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	return (str);
}
