/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 16:17:01 by bwang-do          #+#    #+#             */
/*   Updated: 2018/10/16 16:57:47 by bwang-do         ###   ########.fr       */
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

typedef struct	s_spec
{
	int			flags[3];
	int			width;
	int			prec;
	char		mod[2];
}				t_spec;

typedef struct	s_data
{
	t_spec		*spec;
	int			i;
	char		buff[BUFF_SIZE + 1];
	int			total;
	int			arg_len;
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
char			*ft_strupper(char *str);

char			*ft_get_arg(const char *format, va_list ap, t_data *data);
char			*ft_controller(char c, va_list ap, t_data *data);
char			*ft_nchar(char c, size_t n);
void			*ft_realloccat(void *p1, void *p2, size_t len1, size_t len2);
char			*ft_realloc_free(char *str1, char *str2);
char			*ft_base(long long n, int base);
char			*ft_wchar_to_char(wchar_t wc);
int				ft_printf(const char *format, ...);
char			*ft_width(char *str, int len, t_spec *spec);

char			*ft_conv_c(va_list ap, t_spec *spec, t_data *data);
char			*ft_conv_lc(va_list ap, t_spec *spec, t_data *data);
char			*ft_conv_s(va_list ap, t_spec *spec, t_data *data);
char			*ft_conv_ls(va_list ap, t_spec *spec, t_data *data);
char			*ft_conv_d(va_list ap, t_spec *spec, t_data *data);
char			*ft_conv_ld(va_list ap, t_spec *spec, t_data *data);
char			*ft_conv_o(va_list ap, t_spec *spec, t_data *data);
char			*ft_conv_lo(va_list ap, t_spec *spec, t_data *data);
char			*ft_conv_x(va_list ap, t_spec *spec, t_data *data);
char			*ft_conv_lx(va_list ap, t_spec *spec, t_data *data);
char			*ft_conv_p(va_list ap, t_spec *spec, t_data *data);
char			*ft_conv_u(va_list ap, t_spec *spec, t_data *data);
char			*ft_conv_lu(va_list ap, t_spec *spec, t_data *data);

#endif
