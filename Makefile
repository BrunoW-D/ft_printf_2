# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwang-do <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/10 13:37:42 by bwang-do          #+#    #+#              #
#    Updated: 2018/06/16 18:50:37 by bwang-do         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all re clean fclean norme normelib

CC = gcc

NAME = libftprintf.a

SRC = ft_convert.c \
	  ft_realloc.c \
	  ft_realloc_free.c \
	  ft_wchar_to_char.c \
	  ft_print_controller.c \
	  ft_base.c \
	  ft_nchar.c \
	  new_itoa.c \
	  ft_utoa.c \
	  ft_printf.c \
	  ft_print_s.c \
	  ft_print_ls.c \
	  ft_print_c.c \
	  ft_print_lc.c \
	  ft_print_d.c \
	  ft_print_ld.c \
	  ft_print_o.c \
	  ft_print_lo.c \
	  ft_print_x.c \
	  ft_print_lx.c \
	  ft_print_u.c \
	  ft_print_lu.c \
	  ft_print_p.c \
	  ft_strlower.c \
	  ft_strupper.c \
	  ft_width.c \

LIB_SRC = ft_bzero.c \
		  ft_memset.c \
		  ft_strlen.c \
		  ft_strdup.c \
		  ft_strcpy.c \
		  ft_strcat.c \
		  ft_isdigit.c \
		  ft_strnew.c \
		  ft_putchar.c \
		  ft_putstr.c \
		  ft_strsub.c \

OBJ = $(SRC:.c=.o)

LIB_OBJ = $(LIB_SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ) $(LIB_OBJ)
	ar rc $(NAME) $(OBJ) $(LIB_OBJ)
	ranlib $(NAME)

%.o : %.c
	$(CC) -c $<  

%.o : ./libft/%.c
	$(CC) -c $<

clean:
	/bin/rm -f $(OBJ) $(LIB_OBJ)

fclean: clean
	/bin/rm -f $(NAME)

norme : 
	norminette $(SRC)
	norminette $(addprefix ./libft/, $(LIB_SRC))
	norminette ft.h

re: fclean all
