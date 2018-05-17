/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:56:30 by alecott           #+#    #+#             */
/*   Updated: 2017/11/21 16:15:23 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)malloc(sizeof(*str) * (size + 1));
	if (str == 0)
		return (NULL);
	ft_bzero(str, (size + 1));
	return (str);
}
