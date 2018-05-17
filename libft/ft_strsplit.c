/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 08:43:04 by alecott           #+#    #+#             */
/*   Updated: 2017/11/15 09:01:12 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_word(const char *s, unsigned int ind, char c)
{
	char			*str;
	unsigned int	i;

	i = 0;
	while (s[ind + i] && s[ind + i] != c)
		i++;
	str = ft_strsub(s, ind, i);
	return (str);
}

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	tab = (char**)malloc(sizeof(s) * ft_count_words(s, c) + 1);
	if (tab == NULL)
		return (NULL);
	while (s[i])
	{
		if ((i == 0 && s[i] != c) || (s[i] != c && s[i - 1] == c))
			tab[j++] = ft_word(s, (unsigned int)i, c);
		i++;
	}
	tab[j] = NULL;
	return (tab);
}
