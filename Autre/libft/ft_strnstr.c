/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:02:32 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/17 14:32:01 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t			count;
	unsigned int	needlen;

	count = 0;
	needlen = ft_strlen(needle);
	if (needlen == 0)
		return (((char*)haystack));
	while (haystack[count] && count < len)
	{
		if (!ft_strncmp(&haystack[count], needle, needlen)
				&& ((len - count) >= needlen))
			return (&((char*)haystack)[count]);
		else
			count++;
	}
	return (NULL);
}
