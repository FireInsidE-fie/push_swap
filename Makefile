NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror
RM			=	rm
RMFLAGS		=	-f
SRCDIR		=	src/
CFILES		=	$(SRCDIR)push_swap.c\
				$(SRCDIR)push.c \
				$(SRCDIR)rotate.c \
				$(SRCDIR)swap.c \
				$(SRCDIR)r_rotate.c \
				$(SRCDIR)slab.c \
				$(SRCDIR)input.c
OBJS		=	$(CFILES:.c=.o)
INCLDIR		=	include/
IFILES		=	push_swap.h
LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a

all:			$(NAME)


$(NAME):		$(LIBFT) $(OBJS)
				$(CC) $^ -o $@

%.o:			%.c
				$(CC) $(CFLAGS) -g -c $^ -o $@

$(LIBFT):	 	$(LIBFTDIR)/*.c
				cd $(LIBFTDIR) && make

clean:
				$(RM) $(RMFLAGS) $(OBJS)

fclean:			clean
				$(RM) $(RMFLAGS) $(NAME)
				cd $(LIBFTDIR) && make fclean

re:				fclean all


debug:			$(LIBFT) $(OBJS)
				$(CC) $^ -g -o $@

.PHONY:			all clean fclean re
