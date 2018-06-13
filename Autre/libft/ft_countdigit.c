/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:08:48 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/19 15:25:18 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_countdigit(int n)
{
	int count;

	count = 0;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		count++;
	}
	return (count + 1);
}

int	ft_max_countdigit_base(intmax_t n, int base)
{
	int count;

	count = 0;
	while (n)
	{
		n = n / base;
		count++;
	}
	return (count + 1);
}

int	ft_umax_countdigit_base(uintmax_t n, int base)
{
	int count;

	count = 0;
	while (n)
	{
		n = n / base;
		count++;
	}
	return (count + 1);
}
