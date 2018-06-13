/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:16:13 by mfonteni          #+#    #+#             */
/*   Updated: 2018/05/30 18:01:02 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

void	ft_putstr(char const *s)
{
	if (s)
		write(1, s, ft_strlen(s));
}

int		ft_putstrn(char const *s, int n, int fd)
{
	int count;

	count = 0;
	if (s)
	{
		while (s[count] && count < n)
			ft_putchar_fd(s[count++], fd);
	}
	return ((size_t)count < ft_strlen(s) ? count : (int)ft_strlen(s));
}
