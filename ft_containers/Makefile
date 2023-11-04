## ************************************************************************** ##
##                                 Includes                                   ##
## ************************************************************************** ##

include settings.mk

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
T = test/

BUILD = build/

CC ?= gcc
CFLAGS += -Wall -Wextra -Werror -I$I
CXXFLAGS = -Wall -Wextra -Werror -Wc++11-extensions -I$I
DEBUG = -g
SFLAGS = -fsanitize=address

OBJ = $(SRC:%=$O%.o)
MAIN = $(MAIN_F:%=$O%.o)
MAIN_STD = $(MAIN_STD_F:%=$O%.o)

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

$(MAIN): | $O

$(MAIN): $O%.o: $S%
	@$(CC) $(FLAGS) -c $< -o $@

$(MAIN_STD): | $O

$(MAIN_STD): $O%.o: $S%
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(LIBS) $(OBJ) $(MAIN) $($IINCS) $(MAIN_STD)
	@$(CC) $(FLAGS) $(MAIN) $(OBJ) $(LDFLAGS) $(LIBS) -o $(NAME)
	@$(CC) $(FLAGS) $(MAIN_STD)  $(LDFLAGS) $(LIBS) -o $(STD)
	@echo "\033[0;32mCompiled! Execute as: $(EXECUTION)\033[0m"

## ************************************************************************** ##
##                             Bonus compilation                              ##
## ************************************************************************** ##

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
	@$(RM) $(STD)
	@echo "\033[0;31mExecutable deleted!\033[0m"

re: fclean
	@make

## ************************************************************************** ##
##                               Execution                                    ##
## ************************************************************************** ##

exe: $(NAME)
	@./$(NAME) $(ARG)

$(BUILD):
	cmake -S . -B build

test: $(BUILD)
	@if	$(shell which cmake); then \
		cmake --build build; cd build && ctest; \
	else \
		echo "Error: CMake is not installed on your system. Please install CMake and try again."; \
		exit 1; \
	fi

leak:
	@$(LEAKS) ./build/Vector

segfault: $(LIBS) $(OBJ)
	@$(CC) $(FLAGS) $(SFLAGS) $(OBJ) $(LDFLAGS) $(LIBS) -o $(NAME)
	@echo "\033[0;32mCompiled with segfault flag! Execute as: $(EXECUTION)\033[0m"
#-fsanitize=threads (compiler les objets aussi avec)

debug: $(LIBS) $(OBJ) #Compile for debugger
	@$(CC) $(FLAGS) $(DEBUG) $(OBJ) $(LDFLAGS) $(LIBS) -o $(NAME)
	@echo "\033[0;32mCompiled with -g for debug! Execute as: $(EXECUTION)\033[0m"

list: #Show all make rules
	@grep '^[^#[:space:]].*:' Makefile

.PHONY: all clean fclean re test

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