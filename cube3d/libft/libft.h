/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 15:23:42 by alafranc          #+#    #+#             */
/*   Updated: 2021/02/17 12:07:13 by alafranc         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(char *src);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, unsigned int n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strnstr(const char *str
					, const char *to_find, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);
typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void*));
void				ft_lstclear(t_list **lst, void (*del)(void*));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *)
					, void (*del)(void *));
int					ft_atoi_base(char *str, char *base);
char				*ft_convert_base(char *nbr, char *base_from, char *base_to);
int					ft_strlen_base(int nb, int base_to);
int					is_base_valid(char *str);
int					is_in_base(char c, char *base);
int					ft_factorial(int nb);
int					ft_power(int nb, int power);
int					ft_sqrt(int nb);
int					ft_is_prime(int nb);
int					ft_find_next_prime(int nb);
void				ft_putnbr_base(int nbr, char *base);
void				ft_swap_int(int *a, int *b);
void				ft_swap_char(char **ptr1, char **ptr2);
char				*ft_strrev(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *str);
void				ft_putnbr(int n);
int					ft_size_nb(unsigned long long nb, int base);
char				*ft_remove_first_line(char *file);
char				*fill_filebuf(int fd, char *filebuf, int *b_read, int *eof);
int					get_next_line(int fd, char **line);
size_t				ft_strlen(const char *s);
char				*ft_strdup(char *src);
char				*ft_strjoin_free(char *s1, char *s2);
int					ft_strchr_gnl(char *file, int c);
char				*ft_substr_line(char *s);
typedef struct		s_flags {
	int				display_zero;
	int				space_reverse;
	int				lmc;
	int				nb_precision;
}					t_flags;
int					ft_printf(const char *format, ...)
					 __attribute__((format(printf,1,2)));
int					ft_print_address(va_list ap, t_flags flags);
int					ft_print_char(va_list ap, t_flags flags);
int					ft_print_decimal(va_list ap, t_flags flags);
int					ft_print_string(va_list ap, t_flags flags);
int					ft_print_rate(t_flags flags);
int					ft_print_unsigned(va_list ap, t_flags flags
					, int (f)(unsigned long long), int base);
int					ft_print_arg(const char *format, va_list ap, t_flags flags);
int					ft_putchar_1(char c);
int					ft_putnbr_hexa_count(unsigned long long nb);
int					ft_putstr_count(char *str, int size);
int					ft_putnbr_count(unsigned long long nb);
const char			*parse_flags_lmc(const char *format, t_flags *flags
					, va_list ap);
const char			*parse_flags_precision(const char *format,
								t_flags *flags, va_list ap);
const char			*parse(const char *format, t_flags *flags, va_list ap);
int					ft_display_space(int nb_space);
int					ft_display_zero(int nb_zero);
int					ft_display_space_unsigned(int nb, int size_nb
					, t_flags flags);
int					ft_display_zero_unsigned(int size_nb, t_flags flags);
int					ft_display_nb_unsigned(long nb, int size_nb, t_flags flags
								, int (f)(unsigned long long));
int					ft_putchar_hexa_maj_1(char c);
int					ft_putnbr_hexa_maj_count(unsigned long long nb);
int					ft_zero_exception(t_flags flags);
int					ft_strslen(char **strs);
void				free_all(char **strs, int j);
char				**ft_strsjoin(char **s1, char *s2);
char				**ft_strsdup(char **s1);
int					ft_abs(int nb);
#endif
