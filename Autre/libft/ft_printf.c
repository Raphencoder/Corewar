/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:04:32 by mfonteni          #+#    #+#             */
/*   Updated: 2018/05/30 19:38:16 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <unistd.h>

static int		chars_printer(t_plist *list, int fd)
{
	if (!ischartype(list->type))
	{
		ft_putstr_fd(list->arg, fd);
		return (ft_strlen(list->arg));
	}
	else if (list->isrealarg && (list->type == 'S' || list->type == 's'))
		return (printf_flags_chars(list, fd));
	else if (list->isrealarg && (list->type == 'c' || list->type == 'C'))
		return (printf_flags_char(list, fd));
	else if (!list->isrealarg)
		return (colorprinter(list->arg, fd));
	return (-1);
}

static void		number_controller(t_plist *list)
{
	if (ft_isupper(list->type) && list->type != 'X')
	{
		list->type = ft_tolower(list->type);
		list->length[0] = 'l';
		list->length[1] = '\0';
	}
	if (list->arg == 0 && ft_strchr(list->flag, '#'))
	{
		(ft_strchr(list->flag, '#'))[0] = 'n';
		if (list->type == 'o')
			list->precision == -1 ? list->precision : list->precision++;
	}
	if (ft_strchr(list->flag, '0') && ft_strchr(list->flag, '-'))
		(ft_strchr(list->flag, '0'))[0] = 'n';
	if (list->type == 'i' || list->type == 'd' || list->type == 'D')
		list->arg = (void*)printf_type_d(list);
	else if (list->type == 'o' || list->type == 'u' || list->type == 'x'
			|| list->type == 'X' || list->type == 'p')
		list->arg = (void*)printf_type_unsigned(list);
}

static int		print_controller(t_plist *list, int fd)
{
	int written;
	int errorhandler;

	written = 0;
	errorhandler = 0;
	while (list)
	{
		if (!ischartype(list->type))
		{
			number_controller(list);
			printf_flags_num(list);
			list->length[0] = '\0';
		}
		errorhandler = chars_printer(list, fd);
		if (errorhandler == -1)
			return (-1);
		else
			written += errorhandler;
		list = list->next;
	}
	return (written);
}

int				ft_printf(const char *format, ...)
{
	int		written;
	t_plist	*instructions_list;
	va_list	ap;

	if (!format)
		return (-1);
	written = 0;
	va_start(ap, format);
	instructions_list = parse_input(format, ap);
	written = print_controller(instructions_list, 1);
	va_end(ap);
	printflstdel(instructions_list);
	return (written);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	int		written;
	t_plist	*instructions_list;
	va_list	ap;

	if (!format)
		return (-1);
	written = 0;
	va_start(ap, format);
	instructions_list = parse_input(format, ap);
	written = print_controller(instructions_list, fd);
	va_end(ap);
	printflstdel(instructions_list);
	return (written);
}
