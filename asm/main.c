/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:35:51 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/15 14:08:10 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lem-in/libft/libft.h"
#include <fcntl.h>
void	ft_parsing(char *str);

int main(int argc, char **argv)
{
	int		fd;
	char	*str;
	char	*getall;
	char	*tmp;

	getall = NULL;
	if (!(fd = open(argv[1], O_RDONLY)))
		return (0);
	while (get_next_line(fd, &str))
	{
		if (getall == NULL)
			getall = ft_strdup(str);
		else
			{
				tmp = getall;
				getall = ft_strjoin(tmp, "\n");
				ft_strdel(&tmp);
				tmp = getall;
				getall = ft_strjoin(tmp, str);
				ft_strdel(&tmp);	
			}
	}
	ft_parsing(getall);
	return (0);
}
