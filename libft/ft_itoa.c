/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 12:07:57 by mfonteni          #+#    #+#             */
/*   Updated: 2018/06/28 14:46:30 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	*str;
	int		size;
	int		checkneg;
	long	num;

	size = ft_countdigit(n);
	checkneg = 0;
	num = n;
	if (num < 0)
	{
		size++;
		checkneg = 1;
		num = -num;
	}
	if (!(str = ft_strnew(size)))
		return (NULL);
	if (checkneg)
		str[0] = '-';
	str[size] = '\0';
	while (checkneg ? size > 1 : size >= 0)
	{
		str[--size] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}

static char	*base_table(int isupper)
{
	char	*tab;
	int		count;

	tab = ft_strnew(17);
	count = 0;
	tab[0] = count++ + '0';
	while (count < 10)
	{
		tab[count] = count + '0';
		count++;
	}
	while (count < 16)
	{
		tab[count] = (isupper ? 'A' : 'a') + (count - 10);
		count++;
	}
	tab[count] = '\0';
	return (tab);
}

char		*ft_umax_itoabase(int base, uintmax_t n, int isupper)
{
	char	*str;
	int		size;
	char	*tab;

	size = ft_umax_countdigit_base(n, base) - 1;
	tab = base_table(isupper);
	str = ft_strnew((size > 0 ? size : 1));
	if (str)
		str[0] = '0';
	while (str && n)
	{
		str[--size] = tab[n % base];
		n = n / base;
	}
	free(tab);
	return (str);
}

char		*ft_max_itoabase(int base, intmax_t n, int isupper)
{
	char		*str;
	int			size;
	char		*tab;
	uintmax_t	num;

	size = ft_max_countdigit_base(n, base) - 1;
	tab = base_table(isupper);
	num = (n > 0 ? n : -n);
	if (n < 0)
		size++;
	str = ft_strnew((size > 0 ? size : 1));
	(str ? str[0] = '0' : 0);
	if (str && n < 0)
		str[0] = '-';
	while (str && num)
	{
		str[--size] = tab[num % base];
		num = num / base;
	}
	free(tab);
	return (str);
}
