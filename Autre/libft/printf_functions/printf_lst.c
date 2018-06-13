/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfaddstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:05:45 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/24 11:19:36 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_plist	*printfaddstr(const char *str, int start, int end)
{
	t_plist	*current;
	char	*cutted;

	cutted = ft_strsub(str, start, end - start);
	if (!ft_strlen(cutted))
	{
		ft_memdel((void*)&cutted);
		return (NULL);
	}
	current = printflstnew((void*)cutted);
	current->type = 's';
	return (current);
}

t_plist	*printflstnew(void *arg)
{
	t_plist	*newlist;

	newlist = NULL;
	if (!(newlist = (t_plist*)malloc(sizeof(t_plist))))
		return (NULL);
	if (arg)
		newlist->arg = arg;
	else
		newlist->arg = NULL;
	newlist->flag = ft_strnew(4);
	newlist->width = 0;
	newlist->precision = -1;
	newlist->length = ft_strnew(2);
	newlist->type = -1;
	newlist->isrealarg = 0;
	newlist->ischarexception = 0;
	newlist->next = NULL;
	return (newlist);
}

void	printflstadd(t_plist **alst, t_plist *new)
{
	t_plist *current;

	if (!new)
		return ;
	if (!*alst)
		*alst = new;
	else
	{
		current = *alst;
		while (current->next)
			current = current->next;
		current->next = new;
	}
}

void	printflstdel(t_plist *list)
{
	t_plist *current;
	t_plist *next;

	if (!list)
		return ;
	current = list;
	while (current)
	{
		if (current)
			next = current->next;
		if (current->isrealarg == 0 || !ischartype(current->type))
			ft_memdel((void*)&current->arg);
		ft_memdel((void*)&current->flag);
		ft_memdel((void*)&current->length);
		ft_memdel((void*)&current);
		current = next;
	}
}
