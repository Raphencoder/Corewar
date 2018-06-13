/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:17:57 by abouvero          #+#    #+#             */
/*   Updated: 2018/06/12 12:16:26 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

static int	incorrect_arg(char *opt, char *str, int err)
{
	ft_dprintf(2, "\"%s\"", opt);
	ft_dprintf(2, " \"%s\" : incorrect argument ", str);
	if (err == 1)
		ft_dprintf(2, "(must be between 1 and 2147483647)\n");
	else if (err == 2)
		ft_dprintf(2, "(must contain digits only)\n");
	return (-1);
}

static int	ft_satoi(char *str, char *opt)
{
	int			i;
	long long	final;

	i = 0;
	final = 0;
	if (str[i] == '-' && ft_isdigit(str[i + 1]))
		return (incorrect_arg(opt, str, 1));
	if (!ft_isdigit(str[i]))
		return (incorrect_arg(opt, str, 2));
	while (ft_isdigit(str[i]))
		if ((final = (final * 10) + (str[i++] - 48)) > 2147483647)
			return (incorrect_arg(opt, str, 1));
	if (str[i])
		return (incorrect_arg(opt, str, 2));
	return (!final ? incorrect_arg(opt, str, 1) : (int)final);
}

static int	is_opt(char *opt, char *nbr, t_vm *vm, int *ch_num)
{
	int		num;

	if (!nbr)
	{
		ft_dprintf(2, "\"%s\" : missing argument\n", opt);
		return (usage(-1));
	}
	if ((num = ft_satoi(nbr, opt)) == -1)
		return (-1);
	if (!ft_strcmp(opt, "-n"))
		*ch_num = num;
	else
		vm->dump = num;
	return (1);
}

static int	is_dig_neg(char *str)
{
	char	c;

	c = *str;
	if (known_opt(str))
		return (0);
	if (c == '-' || ft_isdigit(c))
		return (1);
	return (0);
}

int			opt(char **av, int ac, int *i, t_vm *vm)
{
	int		num;

	num = 0;
	while (*av[*i] == '-')
	{
		if (known_opt(av[*i]))
			if (is_opt(av[*i], (*i + 1 == ac || !is_dig_neg(av[*i + 1])
									? 0 : av[*i + 1]), vm, &num) != -1)
				if (*i + 2 == ac)
				{
					if (!vm->champ)
						ft_dprintf(2, "No champ loaded\n");
					return (-2);
				}
				else
					*i += 2;
			else
				return (-1);
		else
			return (illegal_opt(av[*i], -1));
	}
	return (num);
}
