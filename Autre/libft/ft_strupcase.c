/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:39:48 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/17 16:07:47 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strupcase(char *str)
{
	int		count;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count] != '\0')
	{
		str[count] = ft_toupper(str[count]);
		count++;
	}
	return (str);
}
