SRCS		= pipex.c pipex_utilities.c

OBJS		= $(SRCS:.c=.o)

CC			= gcc
CFLAGS		= -Wall -Werror -Wextra

NAME		= pipex
LIBFT		= ./libft/libft.a

all:		$(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): 	$(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)
	@echo "\033[92mDone\033[0m"
clean:
	rm -f $(OBJS) $(LIBFT)
	$(MAKE) -C libft/ clean
	@echo "\033[92mClean\033[0m"
fclean:		clean
	rm -f $(NAME)
	$(MAKE) -C libft/ clean
	@echo "\033[92mFclean\033[0m"
re:			fclean all

.PHONY:		all clean fclean re