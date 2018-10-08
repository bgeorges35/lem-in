# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/13 20:00:07 by bgeorges          #+#    #+#              #
#    Updated: 2018/07/21 20:39:57 by bgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= libft.a
CC				= gcc
FLAGS			= -Wall -Wextra -Werror
DEBUG			= -ggdb
LIBFT_LIB		= lib.a
CPPFLAGS		= -Iinclude
FT_PRINTF_DIR	= ./ft_printf/
FT_PRINTF_LIB	= $(FT_PRINTF_DIR)libftprintf.a


OBJ_PATH		= obj/
CPP_FLAGS		= -Iinclude
HEADER			= libft.h
SRC_NAME 		= ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
				ft_isprint.c \
				ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memdel.c \
				ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c \
				ft_putendl_fd.c \
				ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c ft_putstr.c \
				ft_strcat.c \
				ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c \
				ft_strequ.c \
				ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c \
				ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c ft_tolower.c ft_toupper.c \
				ft_lstadd.c ft_lstnew.c \
				ft_strclen.c \
				ft_itoa_base_lower.c \
				ft_itoa_base_upper.c ft_strilen.c ft_ulltoa.c ft_ltoa.c \
				ft_ultoa_base_lower.c \
				ft_uitoa_base_lower.c ft_uitoa_base_upper.c ft_ltoa_base_lower.c \
				ft_ltoa_base_upper.c ft_ustoa_base_lower.c ft_ulltoa_base_lower.c \
				ft_ulltoa_base_upper.c ft_ultoa_base_upper.c ft_ustoa_base_upper.c \
				ft_uimtoa_base_lower.c ft_uimtoa_base_upper.c ft_lltoa.c ft_stoa.c \
				ft_str_toupper.c  ft_atoll.c ft_strjoin_free.c ft_strjoin_free_2.c \
				ft_atoi_base.c ft_str_tolower.c ft_strsub_free.c ft_strsplit_without.c \
				ft_str_isdigit.c ft_intabdup.c ft_max_tab.c ft_min_tab.c\
				ft_lst_len.c ft_free_lst.c ft_bzero_inttab.c ft_tab_cmp.c \
				ft_cmpintab.c ft_strndup.c ft_lstdup.c ft_strjoin_free_both.c \
				ft_lstlenmin.c ft_is_integer.c ft_display_intab.c ft_display_lst_intab.c \


OBJ_NAME		= $(SRC_NAME:.c=.o)
OBJ				= $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)


$(NAME): $(OBJ)
	@make -C $(FT_PRINTF_DIR) all
	ar rcs $(LIBFT_LIB) $(OBJ)
	libtool -static -o $(NAME) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	ranlib $(NAME)
	rm -f $(LIBFT_LIB)

$(OBJ_PATH)%.o: %.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) $(CPPFLAGS) -o $@ -c $<

debug.c: %.c
	@$(CC) $(DEBUG) $(FLAGS) -c $< -o $@

debug: $(debug.c)
	@$(CC) -c $(DEBUG) $(FLAGS)  $(SRC) -I libft.h
	@ar rcs $(LIBFT_LIB) $(OBJ)
	@libtool -static -o $(NAME) $(LIBFT_LIB) $(FT_PRINTF_LIB)
	@ranlib $(NAME)
	@rm -f $(LIBFT_LIB)

clean:
	make -C $(FT_PRINTF_DIR) clean
	rm -fv $(OBJ)
	rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make -C $(FT_PRINTF_DIR) fclean
	rm -f $(NAME)
	rm -f $(OBJ)

re: fclean all

norme:
	make -C $(FT_PRINTF_DIR) norme
	norminette $(SRC_NAME)
	norminette $(HEADER)

.PHONY: all clean fclean re
