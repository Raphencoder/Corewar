# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 11:15:51 by mfonteni          #+#    #+#              #
#    Updated: 2018/05/30 18:26:25 by mfonteni         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
PRINTFUNC = printf_functions/
SRC = ft_atoi.c \
	  ft_bzero.c \
	  ft_countdigit.c \
	  ft_isalnum.c \
	  ft_isalpha.c \
	  ft_isascii.c \
	  ft_isdigit.c \
	  ft_ispace.c \
	  ft_isupper.c \
	  ft_isprint.c \
	  ft_itoa.c \
	  ft_lstadd.c \
	  ft_lstdel.c \
	  ft_lstdelone.c \
	  ft_lstiter.c \
	  ft_lstmap.c \
	  ft_lstnew.c \
	  ft_memalloc.c \
	  ft_memccpy.c \
	  ft_memchr.c \
	  ft_memcmp.c \
	  ft_memcpy.c \
	  ft_memdel.c \
	  ft_memmove.c \
	  ft_memset.c \
	  ft_print_split.c \
	  ft_putchar.c \
	  ft_putchar_fd.c \
	  ft_putendl.c \
	  ft_putendl_fd.c \
	  ft_putnbr.c \
	  ft_putnbr_fd.c \
	  ft_putstr.c \
	  ft_putstr_fd.c \
	  ft_sqrt.c \
	  ft_strcat.c \
	  ft_strchr.c \
	  ft_strclr.c \
	  ft_strcmp.c \
	  ft_strcpy.c \
	  ft_strdel.c \
	  ft_strdup.c \
	  ft_strequ.c \
	  ft_striter.c \
	  ft_striteri.c \
	  ft_strjoin.c \
	  ft_strlcat.c \
	  ft_strlen.c \
	  ft_strlowcase.c \
	  ft_strmap.c \
	  ft_strmapi.c \
	  ft_strncat.c \
	  ft_strncmp.c \
	  ft_strncpy.c \
	  ft_strnequ.c \
	  ft_strnew.c \
	  ft_strnstr.c \
	  ft_strrchr.c \
	  ft_strrev.c \
	  ft_strsplit.c \
	  ft_strstr.c \
	  ft_strsub.c \
	  ft_strtrim.c \
	  ft_strupcase.c \
	  ft_tolower.c \
	  ft_toupper.c \
	  get_next_line.c \
	  noleaks_get_next_line.c \
	  ft_printf.c \
	  $(PRINTFUNC)printf_lst.c \
	  $(PRINTFUNC)printfparser.c \
	  $(PRINTFUNC)printf_checks.c \
	  $(PRINTFUNC)printf_checks2.c \
	  $(PRINTFUNC)ischartype.c \
	  $(PRINTFUNC)printf_types.c \
	  $(PRINTFUNC)printf_flag_hash.c \
	  $(PRINTFUNC)printf_flags_chars.c \
	  $(PRINTFUNC)printf_flags_num.c \
	  $(PRINTFUNC)colorparser.c \
	  ft_putwchar.c \
	  ft_putwstr.c
COPYPATH = ~/Projects/printf

OBJ = $(SRC:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@ar rcs $(NAME) $^
	@echo "libft.a ready"

%.o:	%.c
	@$(CC) $(FLAGS) -o $@ -c $<

copy:
#	@mkdir $(COPYPATH)
	@cp *.c $(COPYPATH)
	@cp Makefile $(COPYPATH)
	@cp -R $(PRINTFUNC) $(COPYPATH)/$(PRINTFUNC)
	@cp -R includes $(COPYPATH)
	@cp auteur $(COPYPATH)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
