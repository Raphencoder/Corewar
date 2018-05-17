/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:21:46 by alecott           #+#    #+#             */
/*   Updated: 2017/11/15 09:05:14 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (((unsigned char*)s2)[i] != '\0' &&
			((unsigned char*)s1)[i] == ((unsigned char*)s2)[i] && n > i)
		i++;
	if (n == i)
		return (0);
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
