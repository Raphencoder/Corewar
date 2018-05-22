/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkrief <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:35:51 by rkrief            #+#    #+#             */
/*   Updated: 2018/05/22 13:23:04 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/asm.h"

int main(int argc, char **argv)
{
	int			fd;
	char		*str;
	char		*getall;
	header_t	*header;
	char		*tmp;

	(void)argc;
	getall = NULL;
	header = NULL;
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
	ft_parsing(getall, header);
	return (0);
}
