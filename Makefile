NAME	=	push_swap
CC		=	cc
CFLAGS	=	-Wall -Wextra

all:		$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS)

clean:

fclean:		clean

re:			all

.PHONY:		all clean fclean re