NAME = philo

PATH_SRCS = ./sources/
PATH_OBJS = ./objects/
PATH_INCL = ./includes/

SRCS = $(addprefix $(PATH_SRCS), philo.c \
	time.c \
	monitor.c \
	free.c \
	threads.c \
	dinner.c \
	init_data.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))


CFLAGS = -Wall -Wextra -Werror -g3
IFLAGS = -I $(PATH_INCL)

all: $(NAME)

$(NAME): $(OBJS) 
	cc $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) -lpthread

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	cc $(CFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -rf $(PATH_OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

PHONY: all clean fclean re
