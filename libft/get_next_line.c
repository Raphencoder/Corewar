/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 11:59:33 by alecott           #+#    #+#             */
/*   Updated: 2018/02/06 10:23:39 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fd_tracker		*find_fd_tracker_or_add(t_list **lst, const int fd)
{
	t_fd_tracker	*tmp;
	t_list			*lst_tmp;

	lst_tmp = *lst;
	while (lst_tmp)
	{
		tmp = lst_tmp->content;
		if (tmp->fd == fd)
			return (tmp);
		lst_tmp = lst_tmp->next;
	}
	if ((tmp = ft_memalloc(sizeof(t_fd_tracker))) == 0)
		return (0);
	tmp->fd = fd;
	if ((tmp->buf = ft_strnew(0)) == 0)
		return (0);
	if ((lst_tmp = ft_lstnew(tmp, sizeof(t_fd_tracker))) == 0)
		return (0);
	free(tmp);
	ft_lstadd(lst, lst_tmp);
	return (lst_tmp->content);
}

static int				read_and_stock(char **buf, const int fd)
{
	char			tmp_buf[BUFF_SIZE + 1];
	char			*tmp;
	int				readed;

	if ((readed = read(fd, tmp_buf, BUFF_SIZE)) < 0)
		return (-1);
	tmp_buf[readed] = 0;
	tmp = *buf;
	*buf = ft_strjoin(*buf, tmp_buf);
	free(tmp);
	return (readed);
}

static void				copy_and_crop(char **dest, char **src)
{
	size_t		idx;
	char		*tmp;

	idx = 0;
	while ((*src)[idx] != '\n' && (*src)[idx] != 0)
		idx++;
	*dest = ft_strsub(*src, 0, idx);
	if ((*src)[idx] == '\n')
	{
		tmp = *src;
		*src = ft_strsub(*src, idx + 1, ft_strlen(*src) - idx - 1);
		ft_strdel(&tmp);
	}
	else
		ft_strdel(src);
}

static void				free_fd_tracker(t_list **holder, const int fd)
{
	t_fd_tracker	*tmp;
	t_list			*lst;
	t_list			*lst_prev;

	lst = *holder;
	lst_prev = lst;
	while (lst)
	{
		tmp = lst->content;
		if (tmp->fd == fd)
			break ;
		lst_prev = lst;
		lst = lst->next;
	}
	if (lst == 0)
		return ;
	if (lst_prev != lst)
		lst_prev->next = lst->next;
	if (*holder == lst)
		*holder = lst->next;
	if (tmp->buf)
		ft_strdel(&tmp->buf);
	ft_memdel((void **)&lst->content);
	ft_memdel((void **)&lst);
}

int						get_next_line(const int fd, char **line)
{
	static t_list	*holder;
	t_fd_tracker	*fdt;
	int				readed;

	if (fd < 0 || line == 0)
		return (-1);
	*line = 0;
	if ((fdt = find_fd_tracker_or_add(&holder, fd)) == 0)
		return (-1);
	readed = 1;
	while (ft_strchr(fdt->buf, '\n') == 0 && readed > 0)
		if ((readed = read_and_stock(&fdt->buf, fd)) == -1)
			return (-1);
	if (fdt->buf[0] != 0)
	{
		copy_and_crop(line, &fdt->buf);
		if (fdt->buf == 0)
			free_fd_tracker(&holder, fd);
		if (*line == 0)
			return (-1);
		return (1);
	}
	free_fd_tracker(&holder, fd);
	return (0);
}
