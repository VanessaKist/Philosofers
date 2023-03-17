NAME = philo

PATH_SRCS = ./sources/
PATH_OBJS = ./objects/
PATH_INCL = ./includes/
PATH_LIBFT = ./libraries/42_libft/

SRCS = $(addprefix $(PATH_SRCS), philo.c)

OBJS = $(patsubst $(PATH_SRCS)%.c, $(PATH_OBJS)%.o, $(SRCS))

CC = cc
//CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I $(PATH_INCL)
LIBFT = $(PATH_LIBFT)libft.a

all: $(NAME)


$(NAME): $(LIBFT) $(OBJS) 
	@$(CC) $(CFLAGS) $(IFLAGS) -o $(NAME) $(OBJS) $(LIBFT) -lpthread

$(PATH_OBJS)%.o: $(PATH_SRCS)%.c
	@mkdir -p $(PATH_OBJS)
	$(CC) $(CFLAGS) $(IFLAGS) -I ./libraries/42_libft/libft.h -c $< -o $@

$(LIBFT):
	make -C $(PATH_LIBFT)

clean:
	rm -rf $(PATH_OBJS)
	make clean -C $(PATH_LIBFT)
	

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(PATH_LIBFT)
	

re: fclean all

PHONY: all clean fclean re
