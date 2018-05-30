/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:35:51 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/30 21:07:53 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"


void	ft_free_chain(t_chain *block)
{

	while (block->next)
	{
		ft_strdel(&block->content);
		ft_strdel(&block->category);
		block = block->next;
	}
}

int		main(int argc, char **argv)
{
	int			fd;
	char		*str;
	char		*getall;
	header_t	*header;
	t_chain		*block;
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
	block = ft_parsing(getall, header, argv[1]);
//	ft_free_chain(block);
	while (1);
	return (0);
}
