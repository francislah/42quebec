# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 10:55:27 by flahoud           #+#    #+#              #
#    Updated: 2022/07/06 15:50:44 by flahoud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC = src/so_long.c src/play.c src/assets.c \
		src/print.c src/print_string.c src/enemy.c \
		src/validation.c src/map.c \
		src/restart.c src/quit.c

LIBFT = inc/libft
LIBFTA = inc/libft/libft.a

S = src/
O = obj/
I = inc/

CC = gcc
CFLAGS += -Wall -Wextra -Werror
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
	@echo "\033[0;32mCompiling so_long..."
	@make -C $(LIBFT)
	@$(CC) $(LIBFTA) $(OBJ) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "\033[0;32mSo_long compiled! Execute as: './so_long map.ber' or use 'make map'"
	
cleanobj:
	@$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	@$(RMDIR) $O
	@echo "\033[0;31mObjects deleted!"

clean: cleanobjdir
	@make clean -C $(LIBFT)

fclean: clean
	@$(RM) $(NAME)
	@make fclean -C $(LIBFT)
	@echo "Executable deleted!"

re: fclean
	@make

map: $(NAME)
#	@leaks --atExit -- ./so_long maps/noexit.ber
#	@leaks --atExit -- ./so_long maps/nokey.ber
#	@leaks --atExit -- ./so_long maps/nostart.ber
#	@leaks --atExit -- ./so_long maps/nothing.ber
#	@leaks --atExit -- ./so_long maps/nowalls.ber
#	@leaks --atExit -- ./so_long maps/missingonewall.ber
#	@leaks --atExit -- ./so_long maps/fail.bar
#	@leaks --atExit -- ./so_long maps/verybig.ber
#	@leaks --atExit -- ./so_long maps/smallest.ber
	@leaks --atExit -- ./so_long maps/normal.ber
#	@leaks --atExit -- ./so_long maps/big.ber

	
.PHONY: all clean fclean re