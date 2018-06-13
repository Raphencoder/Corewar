/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:22:27 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/17 16:10:21 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strlowcase(char *str)
{
	int		count;

	count = 0;
	if (!str)
		return (NULL);
	while (str[count] != '\0')
	{
		str[count] = ft_tolower(str[count]);
		count++;
	}
	return (str);
}
