## ************************************************************************** ##
##                                 Includes                                   ##
## ************************************************************************** ##

include inc/settings.mk

## ************************************************************************** ##
##                               Variables                                    ##
## ************************************************************************** ##

EXECUTION = ./$(NAME) $(ARG)
#EXECUTION_B = ./$(BONUS) $(ARG)

OBJ = $(SRC:%=$O%.o)
#OBJ_BONUS = $(SRC_BONUS:%=$B%.o)

#Folders
B = obj_bonus/
O = obj/
S = src/
I = inc/

CC ?= gcc
CFLAGS += -Wall -Wextra -Werror
CFLAGS += -I$I
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -I$I
DEBUG = -g
SFLAGS = -fsanitize=address

OBJ = $(SRC:%=$O%.o)
#OBJ_BONUS = $(SRC_BONUS:%=$B%.o)

## ************************************************************************** ##
##                               Compilation                                  ##
## ************************************************************************** ##

all: $(NAME)

$O:
	@mkdir $@
	@echo "\033[0;32mCompiling $(NAME)...\033[0m"

$(OBJ): | $O

$(OBJ): $O%.o: $S%
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBS) $(OBJ) $I$(INCS)
	@$(CC) $(FLAGS) $(OBJ) $(LDFLAGS) $(LIBS) -o $(NAME)
	@echo "\033[0;32mCompiled! Execute as: $(EXECUTION)\033[0m"

## ************************************************************************** ##
##                             Bonus compilation                              ##
## ************************************************************************** ##

#$B:
#	@mkdir $@
#	@echo "\033[0;32mCompiling $(BONUS)...\033[0m"

#$(OBJ_BONUS): | $B

#$(OBJ_BONUS): $B%.o: $S%
#	@$(CC) $(CFLAGS) -c $< -o $@

#$(BONUS): bonus

#bonus: $(LIBS) $(OBJ_BONUS)
#	@$(CC) $(FLAGS) $(OBJ_BONUS) $(LDFLAGS) $(LIBS) -o $(BONUS)
#	@echo "\033[0;32mCompiled! Execute as: ./$(EXECUTION_B)\033[0m"

## ************************************************************************** ##
##                                 Cleaning                                   ##
## ************************************************************************** ##

RM = /bin/rm -f
RMDIR = /bin/rm -rf

cleanobj:
	@$(RM) $(wildcard $(OBJ))
#	@$(RM) $(wildcard $(OBJ_BONUS))

cleanobjdir: cleanobj
	@$(RMDIR) $O
#	@$(RMDIR) $B

clean: cleanobjdir
	@echo "\033[0;31mObjects deleted!\033[0m"

fclean: clean #Delete objects and executable
	@$(RM) $(NAME)
#	@$(RM) $(BONUS)
	@echo "\033[0;31mExecutable deleted!\033[0m"

re: fclean
	@make

## ************************************************************************** ##
##                               Execution                                    ##
## ************************************************************************** ##

exe: $(NAME)
	@./$(NAME) $(ARG)

exe-bonus: $(BONUS)
	@./$(BONUS) $(ARG)

exe-leak: $(NAME)
	@leaks --atExit -- ./$(NAME) $(ARG)
exe-bleak: $(BONUS)
	@leaks --atExit -- ./$(BONUS) $(ARG)
#	@valgrind --leak-check=full --show-leak-kinds=all ./$(NAME) $(MAP)
#	--trace-children=yes

segf: $(LIBS) $(OBJ)
	@$(CC) $(FLAGS) $(SFLAGS) $(OBJ) $(LDFLAGS) $(LIBS) -o $(NAME)
	@echo "\033[0;32mCompiled with segfault flag! Execute as: $(EXECUTION)\033[0m"
segf-bonus: $(LIBS) $(OBJ_BONUS)
	@$(CC) $(FLAGS) $(SFLAGS) $(OBJ_BONUS) $(LDFLAGS) $(LIBS) -o $(BONUS)
	@echo "\033[0;32mCompiled with segfault flag! Execute as: $(EXECUTION_B)\033[0m"
#-fsanitize=threads (compiler les objets aussi avec)

debug: $(LIBS) $(OBJ) #Compile for debugger
	@$(CC) $(FLAGS) $(DEBUG) $(OBJ) $(LDFLAGS) $(LIBS) -o $(NAME)
	@echo "\033[0;32mCompiled with -g for debug! Execute as: $(EXECUTION)\033[0m"
debug-b: $(LIBS) $(OBJ_BONUS) #Compile for debugger
	@$(CC) $(FLAGS) $(DEBUG) $(OBJ_BONUS) $(LDFLAGS) $(LIBS) -o $(NAME)
	@echo "\033[0;32mCompiled with -g for debug! Execute as: $(EXECUTION_B)\033[0m"

list: #Show all make rules
	@grep '^[^#[:space:]].*:' Makefile

.PHONY: all clean fclean re

#Color Codes
#RESET \e[0m
#BLACK \e[1;30m
#RED \e[1;31m
#GREEN \e[1;32m
#YELLOW \e[1;33m
#BLUE \e[1;34m
#MAGENTA \e[1;35m
#CYAN \e[1;36m
#WHITE \e[1;37m