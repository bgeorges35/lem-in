/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:05:35 by bgeorges          #+#    #+#             */
/*   Updated: 2018/07/21 16:10:18 by bgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define BUFF_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>
# include "ft_printf/src/ft_printf.h"

typedef struct		s_list
{
	int				*content;
	int				content_size;
	struct s_list	*next;
}					t_list;

int					ft_atoi(const char *str);
unsigned int		ft_atoi_base(const char *str, int base);
void				ft_bzero(void *s, size_t n);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memmove(void *dst, const void *src, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putstr(char const *s);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
void				ft_strclr(char *s);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dest, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoin_free(char *tmp, char *buff);
char				*ft_strjoin_free_2(char *tmp, char *buff);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
size_t				ft_strlen(const char *str);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dest, const char *src, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strrchr(const char *s, int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strstr(const char *str, const char *to_find);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
t_list				*ft_lstnew(int *content, int content_size);
int					ft_lstadd(t_list **alst, t_list *new);
size_t				ft_strclen(char *str, char c);
char				*ft_str_toupper(char *str);
char				*ft_stoa(short int n);
char				*ft_itoa_base_lower(int n, int base);
char				*ft_itoa_base(int n, int base);
char				*ft_ulltoa(unsigned long long n);
char				*ft_ltoa(long int n);
char				*ft_lltoa(long long n);
int					ft_strilen(int n);
char				*ft_ultoa_base_lower(unsigned long int n, int base);
char				*ft_uitoa_base_lower(unsigned int n, int base);
char				*ft_uitoa_base(unsigned int n, int base);
char				*ft_ltoa_base_lower(long int n, int base);
char				*ft_ltoa_base(long int n, int base);
char				*ft_ustoa_base_lower(unsigned short int n, int base);
char				*ft_ulltoa_base_lower(unsigned long long n, int base);
char				*ft_ulltoa_base(unsigned long long n, int base);
char				*ft_ustoa_base(unsigned short int n, int base);
char				*ft_ultoa_base(unsigned long int n, int base);
char				*ft_uimtoa_base_lower(uintmax_t n, int base);
char				*ft_uimtoa_base(uintmax_t n, int base);
char				*ft_str_tolower(char *str);
long long			ft_atoll(const char *str);
char				*ft_strsub_free(char *s, unsigned int start,
									size_t len);
char				**ft_strsplit_without(char const *s, char c);
int					ft_str_isdigit(char *str);
int					*ft_intabdup(int *tab, int len);
int					ft_min_tab(int *tab, int len);
int					ft_max_tab(int *tab, int len);
int					ft_lst_len(t_list *lst);
void				ft_free_lst(t_list **ways);
void				ft_bzero_inttab(int *tab, int len);
int					ft_tab_cmp(int *tab_1, int len_1, int *tab_2, int len_2);
int					ft_cmpintab(int cmp, int *tab, int len);
char				*ft_strndup(char const *str, int n);
t_list				*ft_lstdup(t_list *lst);
char				*ft_strjoin_free_both(char *tmp, char *buff);
int					ft_lstlenmin(t_list *lst);
int					ft_is_integer(char *str);
void				ft_display_intab(int *tab, int len);
void				display_lst_inttab(t_list *ways);

#endif
