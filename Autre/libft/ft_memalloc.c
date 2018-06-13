/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:58:24 by mfonteni          #+#    #+#             */
/*   Updated: 2018/05/30 19:38:09 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char			*alloc;
	unsigned int	count;

	count = 0;
	if ((alloc = (char*)malloc(sizeof(char) * size)) != NULL)
	{
		while (count < size)
			alloc[count++] = 0;
		return (alloc);
	}
	else
		return (NULL);
}
