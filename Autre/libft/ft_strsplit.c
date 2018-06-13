/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 15:55:23 by mfonteni          #+#    #+#             */
/*   Updated: 2018/04/15 17:24:23 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

int			ft_count_words(char const *s, char separator)
{
	int count;
	int wordcount;
	int counted;

	count = 0;
	wordcount = 0;
	counted = 0;
	while (s[count])
	{
		while (s[count] == separator)
		{
			count++;
			counted = 0;
		}
		while (s[count] != separator && s[count])
		{
			if (counted == 0)
			{
				counted = 1;
				wordcount++;
			}
			count++;
		}
	}
	return (wordcount);
}

static int	count_l(const char *s, int cursor, char separator)
{
	int count;

	count = 0;
	while (s[cursor] != separator && s[cursor])
	{
		cursor++;
		count++;
	}
	return (count + 1);
}

static int	fill_array(const char *str, char **array, char c)
{
	int	cursor;
	int	c1;
	int	c2;

	c1 = 0;
	c2 = 0;
	cursor = 0;
	while (str[cursor])
	{
		if (str[cursor] != c && str[cursor])
		{
			if ((array[c1] = ft_strnew(count_l(str, cursor, c))) == NULL)
				return (0);
			while ((str[cursor] != c) && str[cursor])
				array[c1][c2++] = str[cursor++];
			array[c1++][c2] = '\0';
			c2 = 0;
		}
		else
			cursor++;
	}
	array[c1] = 0;
	return (1);
}

char		**ft_strsplit(char const *s, char c)
{
	char **array;

	if (s != NULL)
	{
		array = (char**)malloc(sizeof(char*) * ft_count_words(s, c) + 1);
		if (array == NULL)
			return (NULL);
		if ((fill_array(s, array, c)) != 0)
			return (array);
	}
	return (NULL);
}
