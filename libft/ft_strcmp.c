/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:19:38 by alecott           #+#    #+#             */
/*   Updated: 2017/11/14 11:29:41 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;

	i = 0;
	while (((unsigned char*)s1)[i] &&
			((unsigned char*)s1)[i] == ((unsigned char*)s2)[i])
		i++;
	return (((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
