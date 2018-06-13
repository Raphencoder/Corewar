/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:51:39 by mfonteni          #+#    #+#             */
/*   Updated: 2017/11/17 12:52:59 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int result;
	int actual;

	result = 1;
	actual = 0;
	while (result <= nb / 2)
	{
		actual = result * result;
		if (actual == nb)
			return (result);
		result = result + 1;
	}
	return (0);
}
