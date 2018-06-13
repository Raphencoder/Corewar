/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 18:02:38 by mfonteni          #+#    #+#             */
/*   Updated: 2018/03/19 15:51:57 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_str_isdigit(char *str)
{
	int count;

	count = 0;
	while (str[count])
	{
		if (!ft_isdigit(str[count]) && str[count] != ' ')
			return (0);
		count++;
	}
	return (1);
}
