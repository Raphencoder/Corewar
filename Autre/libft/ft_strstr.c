/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:45:35 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/25 13:37:28 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (ft_strlen(needle) == 0)
		return (((char*)haystack));
	while (haystack[0])
	{
		if (!ft_strncmp(haystack, needle, ft_strlen(needle)))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
