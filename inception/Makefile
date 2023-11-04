NAME = inception

S = srcs/
COMPOSE = docker compose -p
COMPOSE_FILE = $Sdocker-compose.yml

#Launch with daemon
# FLAG=-d

all: $(NAME)
.PHONY: all

$(NAME):
	@make build
	@make up

build:
	@$(COMPOSE) $(NAME) -f $(COMPOSE_FILE) build
	@echo "\n\033[1;32m*  Containers built  *\033[0m\n"
.PHONY: build

up:
	@$(COMPOSE) $(NAME) -f $(COMPOSE_FILE) up $(FLAG)
	@echo "\n\033[1;33m*  Waiting for everything to connect together  *\033[0m\n"
	@$(COMPOSE) $(NAME) -f $(COMPOSE_FILE) ps
	@echo "\n\033[1;32m*  Containers running  *\033[0m\n"
.PHONY: start

down:
	@$(COMPOSE) $(NAME) -f $(COMPOSE_FILE) down
	@echo "\n\033[1;33m*  Containers down  *\033[0m\n"
.PHONY: stop

restart: down up
.PHONY: restart

status:
	@docker ps
.PHONY: status

network:
	@docker network ls
.PHONY: network

debug:
	@echo "\033[1;33mWhich Container to debug?\033[0m\n"
	@$(COMPOSE) $(NAME) -f $(COMPOSE_FILE) ps
	@printf '\n\033[1;33mEnter Name: \033[0m' && \
	read NAME && docker exec -it $$NAME zsh
.PHONY: debug

logs:
	@echo "\033[1;33mWhich Container to view logs?\033[0m\n"
	@$(COMPOSE) $(NAME) -f $(COMPOSE_FILE) ps
	@printf '\n\033[1;33mEnter Name: \033[0m' && \
	read NAME && docker logs $$NAME
.PHONY: logs

stats:
	@echo "\033[1;33mWhich Container to view stats?\033[0m\n"
	@$(COMPOSE) $(NAME) -f $(COMPOSE_FILE) ps
	@printf '\n\033[1;33mEnter Name: \033[0m' && \
	read NAME && docker stats $$NAME
.PHONY: logs

# Stop and remove images
clean:
	@$(COMPOSE) $(NAME) -f $(COMPOSE_FILE) down --rmi all
	@echo "\n\033[1;31m*  Containers down & images erased  *\033[0m\n"
.PHONY: clean

# Remove all containers, volumes & networks
fclean: clean
	@$(COMPOSE) $(NAME) -f $(COMPOSE_FILE) down --volumes --remove-orphans
	@$(COMPOSE) $(NAME) -f $(COMPOSE_FILE) rm -sfv
	@echo "\n\033[1;31m*  Containers data & networks removed  *\033[0m\n"
.PHONY: fclean

re: fclean all
.PHONY: re

env:
	@echo "Building srcs/.env file\n"
	@echo "MYSQL_HOST=  #Database container name" >> .env
	@echo "MYSQL_DATABASE=" >> .env
	@echo "MYSQL_USER=" >> .env
	@echo "MYSQL_PASSWORD=" >> .env
	@echo "MYSQL_ROOT_PASSWORD=" >> .env
	@echo "WORDPRESS_URL=" >> .env
	@echo "WORDPRESS_TITLE=" >> .env
	@echo "WORDPRESS_ADMIN_USER=" >> .env
	@echo "WORDPRESS_ADMIN_PASSWORD=" >> .env
	@echo "WORDPRESS_ADMIN_EMAIL=" >> .env
	@echo "WORDPRESS_EDITOR_USER=" >> .env
	@echo "WORDPRESS_EDITOR_PASSWORD=" >> .env
	@echo "WORDPRESS_EDITOR_EMAIL=" >> .env
.PHONY: env

# mysql --user= -p
# use database
# select * from ...;