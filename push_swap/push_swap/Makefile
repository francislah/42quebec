# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/19 13:17:13 by flahoud           #+#    #+#              #
#    Updated: 2022/06/15 11:44:10 by flahoud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c sorting.c firstmoves.c secondmoves.c validation.c tools.c big_sort.c index.c

OBJS = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT = libft.a

MAKE = make

MOVE = mv

all: $(NAME)

$(NAME): $(OBJS)
	@$(MAKE) -C libft/
	@$(MOVE) libft/libft.a ./
	@$(CC) $(CFLAGS) $(SRC) $(LIBFT) -o $(NAME)
	@rm -f $(LIBFT)

clean:
	rm -f $(OBJS)
	$(MAKE) -C libft/ clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft/ fclean

re: fclean $(NAME)

.PHONY: all clean fclean re