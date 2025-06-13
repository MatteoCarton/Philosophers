NAME = philo

CC = cc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I includes

GREEN = \033[32m
CYAN = \033[36m
YELLOW = \033[33m
RESET = \033[0m
BLUE = \033[34m
RED = \033[31m

SRCS = \
	src/main/philosophers.c \
	src/main/utils.c \
	src/main/valide_args.c \
	src/main/init.c \
	src/philosophers/actions.c \
	src/philosophers/threads.c \
	src/sync/referee.c \
	src/sync/mutex.c \
	src/sync/time.c \
	src/sync/forks.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(YELLOW)Compiling...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Philosophers are ready to eat, sleep and think (and maybe die)!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "$(RED)Removing object files...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removing executable $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re