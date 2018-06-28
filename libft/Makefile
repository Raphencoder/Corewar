# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecott <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/20 15:48:20 by alecott           #+#    #+#              #
#    Updated: 2018/06/28 14:49:14 by rkrief           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SOURCES = ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c \
		  ft_strcmp.c ft_strdup.c ft_strncat.c ft_strncpy.c ft_tolower.c \
		  ft_bzero.c ft_isalpha.c ft_isdigit.c ft_memcpy.c ft_strcat.c \
		  ft_strcpy.c ft_strlen.c ft_strncmp.c ft_strstr.c ft_toupper.c \
		  ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putchar_fd.c \
		  ft_putendl_fd.c ft_putstr_fd.c ft_putnbr.c ft_putnbr_fd.c ft_strclr.c \
		  ft_strdel.c ft_strnew.c ft_strsub.c ft_strjoin.c ft_strsplit.c \
		  ft_strtrim.c ft_strequ.c ft_strnequ.c ft_striter.c \
		  ft_striteri.c ft_strmap.c ft_strmapi.c ft_memalloc.c ft_memdel.c \
		  ft_strchr.c ft_strrchr.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
		  ft_memmove.c ft_strlcat.c ft_memccpy.c ft_strrev.c ft_lstdel.c \
		  ft_lstadd.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c \
		  ft_count_words.c ft_strrev.c ft_isupper.c ft_itoa.c \
		  get_next_line.c ft_strsubinv.c ft_tablen.c ft_realloc.c ft_tabjoin.c \
		  ft_tabchr.c ft_isnumber.c ft_tabstr.c ft_puttab.c ft_tabdup.c \
		  ft_strndup.c ft_strnmdup.c ft_copy_tab.c ft_itoa_base.c ft_countdigit.c\

OBJETS = $(SOURCES:.c=.o) 

INC = libft.h

all: $(NAME)

$(NAME): $(OBJETS) $(INC)
	@ar rc $(NAME) $(OBJETS)
	@ranlib $(NAME)

%.o: %.c
	gcc -c $< -o $@ $(CFLAGS)

clean:
	@/bin/rm -rf $(OBJETS)

fclean: clean
	@/bin/rm -rf $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re
