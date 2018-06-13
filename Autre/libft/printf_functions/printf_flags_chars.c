/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:40:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/05/30 18:05:51 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	writespaces(int spaces, int fd)
{
	int		count;

	count = 0;
	if (spaces > 0)
	{
		while (count++ < spaces)
			ft_putchar_fd(' ', fd);
	}
	return (spaces);
}

static int	goodstrlen(t_plist *list)
{
	intmax_t	c;

	c = 0;
	if (list->type == 'S' || (list->type == 's' && check_lconv(list)))
		return ((int)ft_wstrlen(list->arg));
	if (list->type == 's' && !check_lconv(list))
		return ((int)ft_strlen(list->arg));
	if (list->type == 'c' && !check_lconv(list))
		return (1);
	if (list->type == 'C' || (list->type == 'c' && check_lconv(list)))
	{
		c = (intmax_t)list->arg;
		return (ft_getbyteslength(c));
	}
	return (0);
}

int			printf_flags_chars(t_plist *list, int fd)
{
	int written;
	int towrite;

	written = 0;
	towrite = (list->precision > -1 && goodstrlen(list) > list->precision
			? list->precision : goodstrlen(list));
	if (list->arg == NULL && (list->type == 's' || list->type == 'S')
			&& list->precision == -1)
		return (ft_putstrn("(null)", 6, fd));
	if (!ft_strchr(list->flag, '-') && towrite < list->width)
		written += writespaces(list->width - towrite, fd);
	if (list->precision > -1 && list->precision < goodstrlen(list))
		written += (list->type == 's' && !check_lconv(list) ?
				ft_putstrn(list->arg, list->precision, fd) :
				ft_putwstrn((wchar_t*)list->arg, list->precision, fd));
	else if (list->type == 's' && !check_lconv(list))
	{
		ft_putstr_fd(list->arg, fd);
		written += goodstrlen(list);
	}
	else
		written += ft_putwstr((wchar_t*)list->arg, fd);
	if (ft_strchr(list->flag, '-') && towrite < list->width)
		written += writespaces(list->width - towrite, fd);
	return (written);
}

int			printf_flags_char(t_plist *list, int fd)
{
	int			written;
	intmax_t	arg;

	arg = (intmax_t)list->arg;
	written = 0;
	if (!ft_strchr(list->flag, '-') && 1 < (size_t)list->width)
		written += writespaces((size_t)list->width - 1, fd);
	if (list->type == 'c' && !check_lconv(list))
	{
		ft_putchar_fd(arg, fd);
		written += 1;
	}
	else
		written += ft_putwchar_fd(arg, fd);
	if (ft_strchr(list->flag, '-') && 1 < (size_t)list->width)
		written += writespaces((size_t)list->width - 1, fd);
	return (written);
}
