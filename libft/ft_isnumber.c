/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 12:02:47 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/22 12:13:05 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *str)
{
	int i;
	int in;

	in = 0;
	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] > 32)
	{
		if (str[i] == ',')
			break ;
		in++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (in)
		return (1);
	else
		return (0);
}
