/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <mfonteni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 11:11:55 by mfonteni          #+#    #+#             */
/*   Updated: 2018/05/30 19:35:19 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <inttypes.h>
# include <unistd.h>
# define BUFF_SIZE 2048

void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
size_t			ft_wstrlen(const wchar_t *s);
char			*ft_strdup(const char *s1);
wchar_t			*ft_wstrdup(const wchar_t *s1);
char			*ft_noleaks_strndup(char *s1, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
wchar_t			*ft_wstrcat(wchar_t *s1, const wchar_t *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
							size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_str_isdigit(char *str);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_isupper(char c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			*ft_memdel(void **ap);
char			*ft_strnew(size_t size);
wchar_t			*ft_wstrnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char*s, void (*f)(char*));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_noleaks_strjoin(char *s1, char *s2);
char			*ft_strtrim(char const *s);
int				ft_count_words(char const *s, char separator);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
int				ft_putstrn(char const *s, int n, int fd);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void			ft_print_split(char **tab);
void			ft_print_split_fd(char **tab, int fd);

int				ft_ispace(char c);
int				ft_countdigit(int n);
int				ft_max_countdigit_base(intmax_t n, int base);
int				ft_umax_countdigit_base(uintmax_t n, int base);
char			*ft_strrev(char *str);
char			*ft_strlowcase(char *str);
char			*ft_strupcase(char *str);
int				ft_sqrt(int nb);
int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

typedef struct	s_plist
{
	void				*arg;
	char				*flag;
	int					width;
	int					precision;
	char				*length;
	char				type;
	int					isrealarg;
	int					ischarexception;
	struct s_plist		*next;
}				t_plist;

t_plist			*printflstnew(void *arg);
void			printflstdel(t_plist *list);
int				is_printf_flag(char c);
int				is_printf_length(char c);
int				is_printf_type(char c);
int				is_signed(char c);
int				is_octal_or_hex(char c);
int				check_lconv (t_plist *list);
int				check_hconv (t_plist *list);
void			printflstadd(t_plist **alst, t_plist *new);
t_plist			*printfaddstr(const char *str, int start, int end);
t_plist			*parse_input(const char *format, va_list ap);
int				ft_putwchar(wchar_t c);
int				ft_putwchar_fd(wchar_t c, int fd);
char			*ft_getwchar(wchar_t c);
int				ft_putwstr(wchar_t *s, int fd);
int				ft_putwstrn(wchar_t *s, int n, int fd);
char			*ft_max_itoabase(int base, intmax_t n, int isupper);
char			*ft_umax_itoabase(int base, uintmax_t n, int isupper);
int				check_hconv(t_plist *list);
int				check_lconv(t_plist *list);
char			*printf_type_d(t_plist *list);
char			*printf_type_unsigned(t_plist *list);
int				ischartype(char c);
void			printf_flag_hash(t_plist *list);
void			printf_flags_num(t_plist *list);
int				printf_flags_chars(t_plist *list, int fd);
int				printf_flags_char(t_plist *list, int fd);
int				ft_getbyteslength(wchar_t c);
int				colorprinter(char *str, int fd);
int				get_next_line(const int fd, char **line);
int				noleaks_get_next_line(const int fd, char **line);
typedef struct	s_fd
{
	int		fd;
	char	*str;
}				t_fd;

#endif
