
#	Library
NAME = 				fdf

# 	Compiler 
CC = 				gcc

#	Flags for norme + LLDB
CFLAGS = 			-Wall -Wextra -Werror -g
GFLAGS =			-lft -lmlx -framework OpenGL -framework AppKit

#	Headers infos
HEA_PATH = 			./
HEA_NAME = 			fdf.h
HEA = 				$(addprefix $(HEA_PATH)/,$(HEA_NAME))

#	Sources infos
SRC_PATH = 			./
SRC_NAME = 			$(shell ls | grep -E "ft_.+\.c")
SRC = 				$(addprefix $(SRC_PATH)/,$(SRC_NAME))		

#	Objects infos
OBJ_PATH = 			./
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
