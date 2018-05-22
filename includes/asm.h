/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:53:02 by alecott           #+#    #+#             */
/*   Updated: 2018/05/22 16:58:57 by rkrief           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_chain
{
	unsigned int	nb_col;
	unsigned int	nb_lines;
	char			*category;
	int				nb_op_tab;
	char			*content;
	struct s_chain	*next;
}					t_chain;

int		main(int argc, char **argv);
void	ft_pass_comment(char *str, int *i);
void	ft_parsing(char *str, header_t *header);
void	ft_is_an_error(char *str, int i);
t_chain	*ft_get_in_chain(char *str, int j);
void	ft_verify_label(char *str, int j, t_chain *block);
#endif
