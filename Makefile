# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgeorges <bgeorges@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/26 14:44:57 by bgeorges          #+#    #+#              #
#    Updated: 2018/07/21 20:39:49 by bgeorges         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= lem-in


SRC_PATH 		= ./src_files/
SRC_NAME		=algo.c \
				algo_basics_functions.c \
				comments.c \
				display.c \
				find_all_ways.c \
				main.c \
				parse.c \
				parse_pipe.c \
				parse_room.c \
				parsing_basics_functions.c \
				solver.c \
				stock_pipe.c \
				stock_room.c \

OBJ_PATH		= obj/
HEADER			= ./lem_in.h
CPP_FLAGS		= -Iinclude
LDFLAGS			= -Llibft
LDLIBS			= -lft
CC				= gcc
FLAGS			= -Wall -Wextra -Werror

OBJ_NAME		= $(SRC_NAME:.c=.o)
SRC				= $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ				= $(addprefix $(OBJ_PATH),$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make all -C ./libft
	$(CC) $(LDFLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER)
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(FLAGS) $(CPP_FLAGS) -o $@ -c $<

clean:
	make clean -C ./libft
	rm -fv $(OBJ)
	rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C ./libft
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
	make norme -C ./libft

.PHONY : clean fclean re all
