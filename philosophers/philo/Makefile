# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flahoud <flahoud@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/07 11:03:40 by flahoud           #+#    #+#              #
#    Updated: 2022/11/08 13:00:28 by flahoud          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

#Use make exe to test && make exe-leak to test the leaks

SRC = src/main.c src/validation.c src/threads.c src/routine.c src/tools.c

S = src/
O = obj/
I = inc/

CC = gcc
CFLAGS += -Wall -Wextra -Werror -g -pthread
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
	@echo "\033[0;32mCompiling philo..."
	@$(CC) $(OBJ) -o $(NAME)
	@echo "\033[0;32mPhilo compiled!"
	@echo "\033[0;34mExecute as: ./philo <philo> <time to die> <time to eat>\
 <time to sleep> +(optional)<eat times>\nOr use: 'make exe' and modify makefile values"
	
cleanobj:
	@$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj
	@$(RMDIR) $O

clean: cleanobjdir
	@echo "\033[0;31mObjects deleted!"

fclean: clean
	@$(RM) $(NAME)
	@echo "Executable deleted!"

re: fclean
	@make

# number of philos / time to die without eat / time to eat / time to sleep / (optional) number of eating repetitions
#ARG = 1 800 200 200		# Philo should die at 800
#ARG = 5 800 200 200		# No philo should die (Don't test the leaks, as it never ends)
#ARG = 200 800 200 200 1	# Simulation should stop after each ate at least 7 times
#ARG = 8 410 200 100		# No philo should die (Don't test the leaks, as it never ends)
#ARG = 8 410 200 100 5	# Stops at 5 meals
#ARG = 4 310 200 100		# One philo should die
#ARG = 2 310 200 100
#ARG = 50 410 200 100
#ARG = 4 310 200 100 1

exe: $(NAME)
	@echo "\033[0;29m"
	./$(NAME) $(ARG)

exe-eat: $(NAME)
	@echo "\033[0;29m"
	@./$(NAME) $(ARG) | grep "is eating" | wc -l
	
exe-leak: $(NAME)
	@echo "\033[0;29m"
	valgrind --show-leak-kinds=all --leak-check=full ./$(NAME) $(ARG)
	
.PHONY: all clean fclean re exe
