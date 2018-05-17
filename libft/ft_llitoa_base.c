/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:47:46 by alecott           #+#    #+#             */
/*   Updated: 2018/01/15 15:01:42 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long long nbr, int base)
{
	int		n;

	n = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		n++;
	while (nbr != 0)
	{
		n++;
		nbr = nbr / base;
	}
	return (n);
}

char		*ft_llitoa_base(long long nbr, int base)
{
	char	*str;
	int		len;

	len = ft_len(nbr, base);
	if (nbr < -9223372036854775807)
		return ("9223372036854775808");
	str = (char*)malloc(sizeof(*str) * (len + 1));
	str[len] = '\0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	while (len >= 0)
	{
		len--;
		if ((nbr % base) < 10 && str[len] != '-')
			str[len] = nbr % base + '0';
		else if (str[len] != '-')
			str[len] = ((nbr % base) + 87);
		nbr = nbr / base;
	}
	return (str);
}
