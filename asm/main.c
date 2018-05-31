/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:35:51 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/31 16:36:19 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"


void	ft_free_chain(t_chain *block)
{
	t_chain		*tmp;
	while (block)
	{
		tmp = block->next;
		if (block->content)
			ft_strdel(&block->content);
		else
			break ;
		if (block->category)
			ft_strdel(&block->category);
		free(block);
		block = tmp;
	}
	free(block);
}

int		main(int argc, char **argv)
{
	int			fd;
	char		*str;
	char		*getall;
	header_t	*header;
	t_chain		*block;
	char		*tmp;
	int			i;

	i = 1;
	if (argc < 2)
	{
		ft_putstr("Usage: ./vm_champs/asm [-a] <sourcefile.s>\n    -a : \
Instead of creating a .cor file, outputs a stripped and annotated version of \
the code to the standard output\n");
		exit (0);
	}
	header = ft_memalloc(sizeof(header_t));
	getall = NULL;
	while (argv[i])
	{
		if (!(fd = open(argv[i], O_RDONLY)))
			return (0);
		if (read(fd, 0, 0) < 0 && !argv[i + 1])
		{
		ft_putstr("Can't read source file ");
		ft_putendl(argv[i]);
		return (0);
		}
		i++;
	}
	while (get_next_line(fd, &str))
	{
		if (getall == NULL)
		{
			getall = ft_strdup(str);
			ft_strdel(&str);
		}
		else
		{
			tmp = getall;
			getall = ft_strjoin(tmp, "\n");
			ft_strdel(&tmp);
			tmp = getall;
			getall = ft_strjoin(tmp, str);
			ft_strdel(&str);
			ft_strdel(&tmp);
		}
	}
	block = ft_parsing(getall, header, argv[i - 1]);
	ft_free_chain(block);
	while (1);
	return (0);
}
