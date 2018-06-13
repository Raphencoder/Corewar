/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:30:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/23 10:58:06 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_straddchar(t_plist *list, int align, char c, size_t toadd)
{
	char	*newstr;
	size_t	count;
	int		checkneg;

	newstr = NULL;
	count = 0;
	checkneg = 0;
	if (list->arg && ((char*)list->arg)[0] == '-' && c == '0' && (checkneg = 1))
		list->arg = ft_noleaks_strndup(list->arg, 1);
	if (list->arg && toadd > 0)
	{
		if (!(newstr = (ft_strnew(ft_strlen(list->arg) + toadd + 1))))
			return ;
		if (!align)
			ft_strcat(newstr, list->arg);
		count = ft_strlen(newstr);
		while (toadd-- > 0)
			newstr[count++] = c;
		if (align)
			ft_strcat(newstr, list->arg);
		ft_memdel((void*)&list->arg);
		list->arg = newstr;
	}
	if (checkneg)
		ft_straddchar(list, 1, '-', 1);
}

static void		futurespaces(t_plist *list)
{
	char	zeroorspace;

	zeroorspace = (list->precision == -1 && list->width != 0 &&
			ft_strchr(list->flag, '0') ? '0' : ' ');
	if (ft_strchr(list->flag, '#'))
	{
		if (list->type == 'o' && list->precision > 1)
			list->precision--;
		else if (list->type == 'o' && ft_strchr(list->flag, '0')
				&& list->precision == -1)
			list->width--;
		else if ((list->type == 'x' || list->type == 'X') && zeroorspace == '0')
			list->width -= 2;
	}
	if ((ft_strchr(list->flag, ' ') || ft_strchr(list->flag, '+'))
			&& is_signed(list->type) && !(ft_strchr(list->arg, '-')))
		list->width--;
	if (list->width < 0)
		list->width = 0;
}

static void		plusflag(t_plist *list)
{
	int		count;
	char	temp;

	count = 0;
	if ((ft_strchr(list->flag, ' ') || ft_strchr(list->flag, '+'))
			&& is_signed(list->type) && !(ft_strchr(list->arg, '-')))
	{
		while (!ft_isdigit(((char*)list->arg)[count]))
			count++;
		if (count > 0)
		{
			temp = ((char*)list->arg)[count - 1];
			((char*)list->arg)[count - 1] =
				(ft_strchr(list->flag, '+') ? '+' : ' ');
			ft_straddchar(list, 1, temp, 1);
		}
		else
			ft_straddchar(list, 1,
					(ft_strchr(list->flag, '+') ? '+' : ' '), 1);
	}
}

static void		width(t_plist *list, int rightalign)
{
	char zeroorspace;

	zeroorspace = ((list->precision == -1 && list->width != 0 &&
			ft_strchr(list->flag, '0')) || (list->type == '%'
			&& list->width > (int)ft_strlen(list->arg)
			&& ft_strchr(list->flag, '0')) ? '0' : ' ');
	if (is_octal_or_hex(list->type) && zeroorspace == ' ')
		printf_flag_hash(list);
	if (list->width != 0 && (size_t)list->width > ft_strlen(list->arg))
		ft_straddchar(list, rightalign, zeroorspace, list->width
				- (int)ft_strlen(list->arg));
	if (is_octal_or_hex(list->type) && zeroorspace == '0')
		printf_flag_hash(list);
	plusflag(list);
}

void			printf_flags_num(t_plist *list)
{
	int		rightalign;
	int		isneg;

	futurespaces(list);
	if (list->type == '%')
	{
		list->arg = ft_strnew(1);
		((char*)list->arg)[0] = '%';
	}
	else if (!list->arg)
	{
		list->arg = ft_strnew(1);
		((char*)list->arg)[0] = '\0';
	}
	isneg = ((ft_strchr(list->arg, '-') != NULL));
	rightalign = (ft_strchr(list->flag, '-') ? 0 : 1);
	if (list->precision > -1 && !(list->type == '%')
			&& (size_t)list->precision > (ft_strlen(list->arg) - isneg))
		ft_straddchar(list, 1, '0', list->precision
				- ft_strlen(list->arg) + isneg);
	width(list, rightalign);
}
