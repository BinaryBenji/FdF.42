# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bzmuda <bzmuda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/30 09:43:03 by bzmuda            #+#    #+#              #
#    Updated: 2017/05/30 09:43:09 by bzmuda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Library
NAME = 				fdf

# 	Compiler 
CC = 				gcc

#	Flags for norme + LLDB
CFLAGS = 			-Wall -Wextra -Werror -g
GFLAGS =			-lmlx -framework OpenGL -framework AppKit

#	Headers infos
HEA_PATH = 			./src
HEA_NAME = 			fdf.h
HEA = 				$(addprefix $(HEA_PATH)/,$(HEA_NAME))

#	Sources infos
SRC_PATH = 			./src
SRC_NAME = 			file_transform.c main.c mapdraw.c utils.c events.c
SRC = 				$(addprefix $(SRC_PATH)/,$(SRC_NAME))		

#	Objects infos
OBJ_PATH = 			./src
OBJ_NAME = 			$(SRC_NAME:.c=.o)
OBJ = 				$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))


###############################################################################


all: $(NAME)

$(NAME): 			$(OBJ) $(HEA)
					@make -C libft/
					@$(CC) $(CFLAGS) $(OBJ) $(GFLAGS) libft/libft.a -o $(NAME)
					@echo "FdF compilation complete."

%.o: 				%.c $(HEA)
					@$(CC) $(CFLAGS) -c $< -o $@ 

clean:				
					@rm -rf $(OBJ)
					@make -C libft clean
					@echo "Object files deleted." 

fclean: 			clean
					@make -C libft fclean
					@rm -rf $(NAME) 
					@echo "Executable deleted." 

re: 				fclean all

.PHONY: 			all clean fclean re


###############################################################################
