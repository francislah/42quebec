# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 10:55:27 by flahoud           #+#    #+#              #
#    Updated: 2022/07/07 10:16:22 by flahoud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRC = src/pipex.c src/validation.c src/tools.c

LIBFT = inc/libft
LIBFTA = inc/libft/libft.a

S = src/
O = obj/
I = inc/

CC = gcc
CFLAGS += -Wall -Wextra -Werror -g
CFLAGS += -I$I
LDFLAGS +=

OBJ = $(SRC:$S%=$O%.o)

RM = /bin/rm -f
RMDIR = /bin/rm -rf

all: $(NAME)

$O:
	@mkdir $@
	@echo "\033[0;32mGenerating objects..."

$(OBJ): | $O

$(OBJ): $O%.o: $S%
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[0;32mCompiling pipex..."
	@make -C $(LIBFT)
	@$(CC) $(LIBFTA) $(OBJ) -o $(NAME)
	@echo "\033[0;32mPipex compiled! Execute as: ./pipex file1 cmd1 cmd2 file2"
	
cleanobj:
	@$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	@$(RMDIR) $O

clean: cleanobjdir
	@make clean -C $(LIBFT)
	@echo "\033[0;31mObjects deleted!"

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@echo "Executable deleted!"

re: fclean
	@make

execute: $(NAME)
	./$(NAME) ../ ls "grep pipex" text1

.PHONY: all clean fclean re
