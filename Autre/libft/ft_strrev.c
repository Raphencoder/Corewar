/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:23:17 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/16 17:41:32 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strrev(char *str)
{
	int		count;
	int		revcount;
	char	*rev;

	count = 0;
	revcount = ft_strlen(str);
	rev = ft_strnew(revcount);
	while (str[count])
		rev[--revcount] = str[count++];
	return (rev);
}
