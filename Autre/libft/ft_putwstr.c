/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:09:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/05/30 18:04:39 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

int		ft_putwstr(wchar_t *s, int fd)
{
	int count;
	int ret;

	count = 0;
	ret = 0;
	if (s)
	{
		while (s[count])
			ret += ft_putwchar_fd((wchar_t)s[count++], fd);
	}
	return (ret);
}

int		ft_putwstrn(wchar_t *s, int n, int fd)
{
	int count;
	int ret;

	count = 0;
	ret = 0;
	if (s)
	{
		while (s[count] && count < n)
			ret += ft_putwchar_fd((wchar_t)s[count++], fd);
	}
	return (ret);
}
