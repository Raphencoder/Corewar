/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:35:51 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/29 13:01:56 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

int main(int argc, char **argv)
{
	int			fd;
	char		*str;
	char		*getall;
	header_t	*header;
	char		*tmp;

	(void)argc;
	header = ft_memalloc(sizeof(header_t));
	getall = NULL;
	if (!(fd = open(argv[1], O_RDONLY)))
		return (0);
	if (read(fd, 0, 0) < 0)
	{
		ft_putendl("Error while trying to read the file");
		return (0);
	}
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
	ft_parsing(getall, header, argv[1]);
	return (0);
}
