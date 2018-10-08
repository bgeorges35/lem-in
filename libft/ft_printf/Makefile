# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/23 11:16:54 by bgeorges          #+#    #+#              #
#    Updated: 2018/07/21 20:41:28 by bgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libftprintf.a

CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
HEADER		=	src/ft_printf.h
CPPFLAGS	= -I$(HEADER)
SRC_PATH	=	./src/
SRC_NAME	=	ft_printf.c \
				ft_find_flags.c \
				ft_find_lenght.c \
				ft_find_specifiers.c \
				ft_find_type.c \
				ft_specifier_dec.c \
				ft_specifier_str.c \
				ft_specifier_base.c \
				ft_get_flags_neg_pos_sp.c \
				ft_get_flags_hash_zero.c \
				ft_find_width.c \
				ft_check_specifiers_flags.c \
				ft_dispatcher_flags.c \
				ft_aff_unicode.c \
				ft_change_width.c \
				ft_transform_wchar_in_char.c \

OBJ_PATH	=	obj/

OBJ_NAME	=	$(SRC_NAME:.c=.o)
SRC			=	$(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ			=	$(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette src/ft_printf.h

.PHONY: all clean fclean re
