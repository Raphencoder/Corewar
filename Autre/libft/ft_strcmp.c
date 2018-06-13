/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:19:04 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/17 15:04:37 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	int count;

	count = 0;
	while (s1[count] == s2[count] && (s1[count] || s2[count]))
		count++;
	return (((unsigned char*)s1)[count] - ((unsigned char *)s2)[count]);
}
