/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:40:13 by mfonteni          #+#    #+#             */
/*   Updated: 2018/05/30 18:18:53 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		is_negative;
	int		final;

	i = 0;
	final = 0;
	is_negative = 0;
	while (ft_ispace(str[i]) || str[i] == '\v' || str[i] == '\f'
	|| str[i] == '\r' || (str[i] == '+' && ft_isdigit(str[i + 1])))
		i++;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		is_negative = i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		final = (final * 10) + (str[i++] - 48);
	if (is_negative)
		return (-final);
	return (final);
}
