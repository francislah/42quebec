# **************************************************************************** #
#                                 Variables                                    #
# **************************************************************************** #

NAME	= brain
EX		= cpp01_ex02

GIT_REPO = origin

EXECUTION = ./$(NAME)

SRC = 	main.cpp
	
O = obj/
I = inc/

CC = c++
CFLAGS += -Wall -Wextra -Werror -std=c++98
CFLAGS += -I$I
LDFLAGS +=

OBJ = $(SRC:%=$O%.o)

RM = /bin/rm -f
RMDIR = /bin/rm -rf

# **************************************************************************** #
#                                 Compilation                                  #
# **************************************************************************** #

all: $(NAME)

$O: #Create obj directory
	@mkdir $@
	@echo "\033[0;32mGenerating objects...\033[0m"

$(OBJ): | $O

$(OBJ): $O%.o: % #Build objects $< take the name on the right of ":", $@ take the name on the left of ":"
	@$(CC) $(CFLAGS) -c $< -o $@
	
$(NAME): $(OBJ) #Libft will compile only once, use "make libft" to recompile
	@echo "\033[0;32mCompiling $(NAME)...\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m$(NAME) compiled! Execute as: $(EXECUTION)\033[0m"

# **************************************************************************** #
#                                    Cleaning                                  #
# **************************************************************************** #

cleanobj: #Delete .o files in obj directory
	@$(RM) $(wildcard $(OBJ))

cleanobjdir: cleanobj #Delete obj directory
	@$(RMDIR) $O

clean: cleanobjdir #Delete obj directory and content
	@echo "\033[0;31m$(EX) objects deleted!\033[0m"

fclean: clean #Delete objects and executable
	@$(RM) $(NAME)
	@$(RM) .DS_STORE
	@$(RMDIR) $(NAME).dSYM
	@echo "\033[1;31m	$(NAME) executable deleted!\033[0m"

re: fclean #Delete all and rebuild executable
	@make

# **************************************************************************** #
#                                 Execution                                    #
# **************************************************************************** #

debug: $(OBJ) #Compile for debugger
	@echo "\033[0;32mCompiling $(NAME)...\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@echo "\033[0;32m$(NAME) compiled! Execute as: $(EXECUTION)\033[0m"

segfault: $(OBJ)
	@$(CC) $(CFLAGS) -fsanitize=address $(OBJ) -o $(NAME)
	
exe: $(NAME) #Execute program
	@printf '\nEntrer les paramètres à passer au programme: ' && read PARAMS && \
	./$(NAME) $$PARAMS

exe-leak: $(NAME)
	valgrind --leak-check=full --trace-children=yes --track-origins=yes --show-leak-kinds=all ./$(NAME)

# **************************************************************************** #
#                                  Git Tools                                   #
# **************************************************************************** #

gitupdate:
	printf '\nEnter pull or fetch to update from Origin: ' && read PULLFETCH && \
	printf '\nEnter Branch Name (Press Enter For All Branches): ' && \
	read BRANCH && git $$PULLFETCH origin $$BRANCH

gitadd: fclean #Clean repo before adding files to git
	git add *

gitcommit: gitadd #Commit modifications locally before push, takes user input for commit's name
	@printf '\nEnter Commit Name: '
	@read COMMIT && git commit -m $$COMMIT

gitpush: gitcommit #Push commit to remote repo
	@printf '\nEnter Branch To Push (Press Enter For ALL): '
	@read PUSH && git push $(GIT_REPO) $$PUSH

gitmerge: #Merge specific branch to current branch
	@printf '\nEnter Branch To Merge With (Press Enter To Merge ALL): '
	@read MERGE && git merge $$MERGE && git merge $$MERGE

gitfetch: #Fetch to update branches without merging with local repo
	@printf '\nEnter Branch To Fetch (Press Enter For All Branches): '
	@read FETCH && git fetch $(GIT_REPO) $$FETCH
	
gitpull: #Pull to overwrite local data if repo is different
	@printf '\nEnter Branch To Pull (Press Enter For All Branches): '
	@read PULL && git pull $(GIT_REPO) $$FETCH

list: 	#Show all make rules
	@grep '^[^#[:space:]].*:' Makefile

.PHONY: all clean fclean re
