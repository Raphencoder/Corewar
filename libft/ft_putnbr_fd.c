/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:58:15 by alecott           #+#    #+#             */
/*   Updated: 2017/11/14 09:52:50 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	i;

	i = (long int)n;
	if (i < 0)
	{
		i = i * -1;
		ft_putchar_fd('-', fd);
	}
	if (i >= 10)
	{
		ft_putnbr_fd(i / 10, fd);
	}
	ft_putchar_fd(i % 10 + '0', fd);
}
