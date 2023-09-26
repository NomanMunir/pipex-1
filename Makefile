# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/10 15:18:50 by abashir           #+#    #+#              #
#    Updated: 2023/09/26 14:46:44 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

# NAME_B = checker

LIBFT = libft

SRC = 	main.c \
		init.c \
		utils.c \
		error.c \
		libs/get_next_line/get_next_line.c \
		libs/get_next_line/get_next_line_utils.c \
	
# SRC_B = check_args.c \
# 		free.c \
# 		utils.c \
# 		lst_fcn.c \
# 		operation_1.c \
# 		operation_2.c \
# 		operation_3.c \
# 		create_stack.c \
# 		bonus/checker.c \
# 		get_next_line/get_next_line.c \
# 		get_next_line/get_next_line_utils.c \
# 		bonus/implement_inst.c \
# 		bonus/read_inst.c \

INC = -I get_next_line
ARC = libs/libft/libft.a
CC = cc

# CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT)
	$(CC) $(CFLAGS) $(SRC) $(ARC) -o $(NAME)
	
$(LIBFT):
	cd libs/libft && make

# bonus: $(LIBFT) $(OBJ_B)
# 	$(CC) $(OBJ_B) $(CFLAGS) $(ARC) -o $(NAME_B)
	
clean:
	rm -f -v $(OBJ) $(OBJ_B)
	cd libft && make clean

fclean: clean
	rm -f $(NAME) $(NAME_B)
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re libft bonus
