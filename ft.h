/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:17:01 by bwang-do          #+#    #+#             */
/*   Updated: 2018/06/16 18:51:06 by bwang-do         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# define BUFF_SIZE 4
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <wchar.h>

# include <stdio.h>

typedef struct	s_flags
{
	int			options[5];
	char		modifier[2];
}				t_flags;

typedef struct	s_data
{
	t_flags		*flags;
	int			i;
	char		buff[BUFF_SIZE + 1];
	int			total;
}				t_data;

void			ft_bzero(void *str, size_t n);
size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strcat(char *dest, const char *src);
int				ft_isdigit(int c);
char			*ft_strnew(size_t size);
void			ft_putchar(char c);
void			ft_putstr(char const *str);
char			*ft_strsub(char const *s, unsigned int start, size_t len);

char			*new_itoa(long long n);
char			*ft_utoa(unsigned long long n);
char			*ft_strlower(char *str);
char			*ft_strupper(char *str);

char			*ft_get_flags(const char *format, va_list ap, t_data *data);
char			*ft_print_controller(char c, va_list ap, t_data *data);
char			*ft_nchar(char c, size_t n);
char			*ft_realloc(char *str1, const char *str2);
char			*ft_realloc_free(char *str1, char *str2);
char			*ft_base(long long n, int base);
char			*ft_wchar_to_char(wchar_t wc);
int				ft_printf(const char *format, ...);
char			*ft_width(char *str, int len, t_flags *flags);

char			*ft_print_c(va_list ap, t_flags *flags);
char			*ft_print_lc(va_list ap, t_flags *flags);
char			*ft_print_s(va_list ap, t_flags *flags);
char			*ft_print_ls(va_list ap, t_flags *flags);
char			*ft_print_d(va_list ap, t_flags *flags);
char			*ft_print_ld(va_list ap, t_flags *flags);
char			*ft_print_o(va_list ap, t_flags *flags);
char			*ft_print_lo(va_list ap, t_flags *flags);
char			*ft_print_x(va_list ap, t_flags *flags);
char			*ft_print_lx(va_list ap, t_flags *flags);
char			*ft_print_p(va_list ap, t_flags *flags);
char			*ft_print_u(va_list ap, t_flags *flags);
char			*ft_print_lu(va_list ap, t_flags *flags);

#endif
