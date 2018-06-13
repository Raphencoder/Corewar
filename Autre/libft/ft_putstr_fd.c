/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 11:59:47 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/15 15:04:47 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int count;

	count = 0;
	if (s)
	{
		while (s[count] != '\0')
		{
			ft_putchar_fd(s[count], fd);
			count++;
		}
	}
}
