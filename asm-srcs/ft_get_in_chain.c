/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_in_chain.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:04:44 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/17 12:00:00 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../lem-in/libft/libft.h"
#include "../includes/op.h"
#include <stdio.h>

void	ft_get_in_chain(char *str, int j)
{
	ft_putstr("---");
	ft_putchar(str[j]);
	ft_putnbr(j);
	ft_putstr("---");

}
