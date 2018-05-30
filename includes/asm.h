/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corewar.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecott <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 14:53:02 by alecott           #+#    #+#             */
/*   Updated: 2018/05/30 10:06:18 by alecott          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct		s_chain
{
	char			*content;
	char			*category;
	int				index;
	int				arg_type;
	int				size;
	unsigned int	nb_col;
	unsigned int	nb_lines;
	int				nb_op_tab;
	struct s_chain	*next;
}					t_chain;

typedef struct		s_op
{
	char			*str;
	int				nb_args;
	int				args[3];
	int				opcode;
	int				nb_cycles;
	char			*name;
	int				ocp;
	int				label_size;
}					t_op;

extern t_op			op_tab[];

int		main(int argc, char **argv);
void	ft_pass_comment(char *str, int *i);
void	ft_parsing(char *str, header_t *header, char *str2);
void	ft_is_an_error(char *str, int i);
t_chain	*ft_get_in_chain(char *str, int j);
int		ft_complete_content(t_chain *block, char *str, int *i);
int		ft_put_line_in_block(t_chain *b, int *i, char *str);
void	ft_verify_label(char *str, int j, t_chain *block);
t_op	*ft_search_op(char *str);
void	ft_asm(char *str, t_chain *block, header_t *header);
t_chain	*ft_arg_type(t_chain *block);
void	ft_putint_bin(int n, int fd);
void	ft_putshort_bin(short n, int fd);
void	ft_putstr_bin(char *str,int fd);
void	ft_OCP(t_chain *block, int fd);
void	ft_write_cor(int fd, header_t *header, t_chain *block);
void	ft_nbr_link(t_chain *block);
char	*ft_find_label(t_chain *block, t_chain *start);

#endif
