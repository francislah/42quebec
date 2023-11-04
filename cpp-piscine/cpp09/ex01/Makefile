## ************************************************************************** ##
##                                 Includes                                   ##
## ************************************************************************** ##

include inc/settings.mk

## ************************************************************************** ##
##                               Variables                                    ##
## ************************************************************************** ##

EXECUTION = ./$(NAME) $(ARG)

OBJ = $(SRC:%=$O%.o)

#Folders
B = obj_bonus/
O = obj/
S = src/
I = inc/

CXXFLAGS = -Wall -Wextra -Werror -std=c++98
CXXFLAGS += -I$I
DEBUG = -g
SFLAGS = -fsanitize=address

OBJ = $(SRC:%=$O%.o)

## ************************************************************************** ##
##                               Compilation                                  ##
## ************************************************************************** ##

all: $(NAME)
.PHONY: all

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
##                                 Cleaning                                   ##
## ************************************************************************** ##

RM = /bin/rm -f
RMDIR = /bin/rm -rf

cleanobj:
	@$(RM) $(wildcard $(OBJ))
.PHONY: cleanobj

cleanobjdir: cleanobj
	@$(RMDIR) $O
.PHONY: cleanobjdir

clean: cleanobjdir
	@echo "\033[0;31mObjects deleted!\033[0m"
.PHONY: clean

fclean: clean #Delete objects and executable
	@$(RM) $(NAME)
#	@$(RM) $(BONUS)
	@echo "\033[0;31mExecutable deleted!\033[0m"
.PHONY: fclean

re: fclean
	@make
.PHONY: re

## ************************************************************************** ##
##                               Execution                                    ##
## ************************************************************************** ##

exe: $(NAME)
	@echo "\033[0;32mExecuting ./$(NAME) $(ARG)\033[0m"
	@./$(NAME) $(ARG)
.PHONY: exe

leak: $(NAME)
	@$(LEAKS) ./$(NAME) $(ARG)
.PHONY: leak

segfault: $(LIBS) $(OBJ)
	@$(CC) $(FLAGS) $(SFLAGS) $(OBJ) $(LDFLAGS) $(LIBS) -o $(NAME)
	@echo "\033[0;32mCompiled with segfault flag! Execute as: $(EXECUTION)\033[0m"
.PHONY: segfault

debug: $(LIBS) $(OBJ) #Compile for debugger
	@$(CC) $(FLAGS) $(DEBUG) $(OBJ) $(LDFLAGS) $(LIBS) -o $(NAME)
	@echo "\033[0;32mCompiled with -g for debug! Execute as: $(EXECUTION)\033[0m"
.PHONY: debug

list: #Show all make rules
	@grep '^[^#[:space:]].*:' Makefile
.PHONY: list

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