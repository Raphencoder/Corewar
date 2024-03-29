/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:35:51 by rkrief            #+#    #+#             */
/*   Updated: 2018/06/28 16:23:50 by rkrief           ###   ########.fr       */
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
		if (block->category)
			ft_strdel(&block->category);
		free(block);
		block = tmp;
	}
}

void	ft_into_the_while(char **getall, char *str)
{
	char *tmp;

	tmp = NULL;
	if (*getall == NULL)
	{
		*getall = ft_strdup(str);
		ft_strdel(&str);
	}
	else
	{
		tmp = *getall;
		*getall = ft_strjoin(tmp, "\n");
		ft_strdel(&tmp);
		tmp = *getall;
		*getall = ft_strjoin(tmp, str);
		ft_strdel(&str);
		ft_strdel(&tmp);
	}
}

void	ft_check_error_parse(int *fd, int *i, char **argv)
{
	if (!(*fd = open(argv[*i], O_RDONLY)))
		exit(0);
	if (read(*fd, 0, 0) < 0 && !argv[*i + 1])
	{
		ft_putstr("Can't read source file ");
		ft_putendl(argv[*i]);
		exit(0);
	}
	*i = *i + 1;
}

int		main(int argc, char **argv)
{
	t_chain		*block;
	t_header	header;
	t_main		main;

	main.nb = 1;
	if (argc < 2)
	{
		ft_putstr("Usage: ./vm_champs/asm [-a] <sourcefile.s>\n    -a : \
Instead of creating a .cor file, outputs a stripped and annotated version of \
the code to the standard output\n");
		exit(0);
	}
	main.getall = NULL;
	while (argv[main.nb])
		ft_check_error_parse(&main.fd, &main.nb, argv);
	while (get_next_line(main.fd, &main.str))
		ft_into_the_while(&main.getall, main.str);
	block = ft_parsing(main.getall, &header, argv[main.nb - 1]);
	ft_strdel(&main.getall);
	ft_free_chain(block);
	return (0);
}
