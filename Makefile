# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecott <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/17 11:04:33 by alecott           #+#    #+#              #
#    Updated: 2018/05/22 15:28:08 by rkrief           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS = -Wall -Werror -Wextra -g

LIB_PATH = ./libft/

ASM_PATH = ./asm/

CWR_PATH = ./corewar/

INC_PATH = ./includes/

ASM_NAME = ./asm/asm

CWR_NAME = corewar

LIB_NAME = libft.a

LIB = $(addprefix $(LIB_PATH), $(LIB_NAME))

LIB_INC = $(addprefix $(LIB_PATH), libft.h)

ASM_INC = $(addprefix $(INC_PATH), asm.h)

ALL_LIB_SRCS = ft_atoi.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_memset.c \
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
		  ft_tabchr.c ft_tabstr.c ft_puttab.c ft_tabdup.c ft_strndup.c \
		  ft_strnmdup.c ft_copy_tab.c 

ALL_ASM_SRCS = op.c ft_get_in_chain.c ft_is_an_error.c ft_parsing.c ft_pass_comment.c main.c

ALL_CWR_SRCS = 

LIB_SRCS = $(addprefix $(LIB_PATH), $(ALL_LIB_SRCS))

ASM_SRCS = $(addprefix $(ASM_PATH), $(ALL_ASM_SRCS))

CWR_SRCS = $(addprefix $(CWR_PATH), $(ALL_CWR_SRCS))

LIB_OBJ = $(LIB_SRCS:.c=.o)

ASM_OBJ = $(ASM_SRCS:.c=.o)

CWR_OBJ = $(CWR_SRCS:.c=.o)

all: $(ASM_NAME) #$(CWR_NAME)

#$(CWR_NAME): $(CWR_OBJ) $(LIB_OBJ) $(LIB_INC) $(INC)
#	@$(MAKE) -C libft
#	@gcc $(CFLAGS) $(CWR_OBJ) -L libft -lft -o $(CWR_NAME)
#
#%.o:$(CWR_PATH)%.c
#	gcc -c $< -o $@ $(CFLAGS)
#
$(ASM_NAME): $(ASM_OBJ) #$(LIB_OBJ) $(LIB_INC) $(ASM_INC)
	@$(MAKE) -C libft
	@gcc $(CFLAGS) $(ASM_OBJ) -L libft -lft -o $(ASM_NAME)

%.o:$(ASM_PATH)%.c
	gcc -c $< -o $@ $(CFLAGS)

clean:
	@$(MAKE) -C libft $@
	@/bin/rm -f $(ASM_OBJ) #$(CWR_OBJ)

fclean: clean
	@$(MAKE) -C libft $@
	@/bin/rm -f $(ASM_NAME) #$(CWR_NAME)

re: fclean $(ASM_NAME) #$(CWR_NAME)

.PHONY: all clean fclean re
