/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_champ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abouvero <abouvero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/25 10:35:19 by abouvero          #+#    #+#             */
/*   Updated: 2018/06/12 11:59:31 by abouvero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/corewar.h"

int				fill_id_champs(t_vm *vm)
{
	t_champ		*ch;
	int			i;

	ch = vm->champ;
	i = 1;
	if (!ch)
		return (usage(0));
	while (ch)
	{
		while (!check_num(vm->champ, i))
			i++;
		if (!ch->id)
			ch->id = i++;
		ch = ch->next;
	}
	return (sort_champs(vm));
}

static int		get_b_size(unsigned char *b_size)
{
	unsigned int	size;
	int				i;

	i = -1;
	size = 0;
	while (++i < 4)
	{
		size |= b_size[i];
		size <<= 8;
	}
	return (size >> 8);
}

static int		check_magic(int fd)
{
	unsigned char	magic[4];
	int				i;

	i = -1;
	if (read(fd, magic, 4) != 4)
		return (0);
	while (++i < 4)
		if (((COREWAR_EXEC_MAGIC >> (i * 8)) & 0x000000FF) != magic[3 - i])
			return (0);
	return (1);
}

static int		fill_header(int fd, t_champ *champ)
{
	unsigned char	size_b[4];

	if (read(fd, champ->name, PROG_NAME_LENGTH + 4) != PROG_NAME_LENGTH + 4)
		return (0);
	champ->name[PROG_NAME_LENGTH] = '\0';
	if (read(fd, size_b, 4) != 4)
		return (0);
	champ->size = get_b_size(size_b);
	if (read(fd, champ->comment, COMMENT_LENGTH + 4) != COMMENT_LENGTH + 4)
		return (0);
	champ->comment[COMMENT_LENGTH] = '\0';
	return (1);
}

t_champ			*parse_champ(char *file_name, t_champ *champ)
{
	int		fd;

	if (!(fd = open(file_name, O_RDONLY)) || fd < 0)
		return (error_file("Couldn't open file \"%s\"\n", file_name, champ));
	if (!(check_magic(fd)) || !fill_header(fd, champ))
		return (error_file("Invalid header in \"%s\"\n", file_name, champ));
	if (champ->size > CHAMP_MAX_SIZE)
	{
		ft_dprintf(2, "File \"%s\" is too large : %d bytes instead of\
%d bytes.\n", file_name, champ->size, CHAMP_MAX_SIZE);
		return (rec_free_champs(champ));
	}
	if (!(champ->code = (unsigned char *)ft_memalloc(sizeof(char) * \
			champ->size)) || read(fd, champ->code, champ->size) != champ->size)
		return (error_file("Invalid header in \"%s\"\n", file_name, champ));
	if (close(fd))
		return (error_file("Couldn't close file \"%s\"\n", file_name, champ));
	return (champ);
}
