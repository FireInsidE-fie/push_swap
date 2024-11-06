NAME		=	push_swap
CC			=	cc
CFLAGS		=	-Wall -Wextra
RM			=	rm
RMFLAGS		=	-f
SRCDIR		=	src/
CFILES		=	$(SRCDIR)push_swap.c\
				$(SRCDIR)push.c \
				$(SRCDIR)rotate.c \
				$(SRCDIR)swap.c \
				$(SRCDIR)r_rotate.c
OBJS		=	$(CFILES:.c=.o)
INCLDIR		=	include/
IFILES		=	push_swap.h
LIBFTDIR	=	libft
LIBFT		=	$(LIBFTDIR)/libft.a

all:		$(NAME)


$(NAME):	$(LIBFT) $(OBJS)
			$(CC) $^ -o $@

%.o:		%.c
			$(CC) $(CFLAGS) -c $^ -o $@

$(LIBFT): 	$(LIBFTDIR)/*.c
			cd $(LIBFTDIR) && make

clean:
			$(RM) $(RMFLAGS) $(OBJS)

fclean:		clean
			$(RM) $(RMFLAGS) $(NAME)
			cd $(LIBFTDIR) && make fclean

re:			fclean all


.PHONY:		all clean fclean re
