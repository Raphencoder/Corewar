/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 15:01:15 by alecott           #+#    #+#             */
/*   Updated: 2018/02/28 12:48:04 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t prev_size, size_t new_size)
{
	void	*dst;

	if (prev_size >= new_size)
		return (ptr);
	if ((dst = malloc(new_size)) == 0)
	{
		free(ptr);
		return (0);
	}
	ft_memcpy(dst, ptr, prev_size);
	free(ptr);
	return (dst);
}
