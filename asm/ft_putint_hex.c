/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint_bin.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/24 09:27:01 by alecott           #+#    #+#             */
/*   Updated: 2018/05/24 13:28:16 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/asm.h"

void	ft_putint_bin(int n, int fd)
{
	ft_putchar_fd((n >> 24) & 0xff, fd);
	ft_putchar_fd((n >> 16) & 0xff, fd);
	ft_putchar_fd((n >> 8) & 0xff, fd);
	ft_putchar_fd(n & 0xff, fd);
}

void	ft_putshort_bin(short n, int fd)
{
	ft_putchar((n >> 8) & 0xff);
	ft_putchar(n & 0xff);
}

void	ft_putstr_bin(char *str, int fd)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar_fd(str[i] & 0xff, fd);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		n;
	char	*str;
	int		fd;

	n = 42;
	str = ".name ";
	fd = open("test", O_WRONLY | O_CREAT);
	if (fd < 0)
	{
		ft_putendl("open error");
		return (0);
	}
	ft_putstr_bin(str, fd);
	return (0);
}
