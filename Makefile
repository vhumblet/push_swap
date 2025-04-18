SRCS =		check_av.c  	\
			feel_free.c 	\
			movement.c  	\
			movement2.c 	\
			movement3.c		\
			parsing.c		\
			sort_index.c	\
			split.c 		\
			utils.c			\
			algo.c			\
			main.c			\

NAME = push_swap
OBJS = $(SRCS:.c=.o)
REMOVE = rm -rf

CC = cc

CC_FLAGS = -Wall -Wextra -Werror

.c.o:
		$(CC) $(CC_FLAGS) -c $< -o $(<:.c=.o)
all: $(NAME)

$(NAME): $(OBJS)
				$(NAME) $(OBJS)

clean:
		$(REMOVE) $(OBJS)
		@echo ".o Delete"

fclean: clean
				$(REMOVE) $(NAME)

re: fclean clean all

.PHONY:		all clean fclean re