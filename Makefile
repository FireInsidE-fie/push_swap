NAME		=	push_swap
CC			=	gcc
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
				$(SRCDIR)utils.c \
				$(SRCDIR)input.c \
				$(SRCDIR)sort_utils.c \
				$(SRCDIR)melodies.c \
				$(SRCDIR)radix.c \
				$(SRCDIR)reflection.c
OBJS		=	$(CFILES:.c=.o)
INCLDIR		=	include/
IFILES		=	push_swap.h
LIBFTDIR	=	libftprintf/
LIBFT		=	$(LIBFTDIR)libftprintf.a

all:			$(NAME)


$(NAME):		$(OBJS) $(LIBFT)
				$(CC) $(CFLAGS) $^ -o $@

%.o:			%.c
				$(CC) $(CFLAGS) -g -c $^ -o $@

$(LIBFT):	 	$(LIBFTDIR)/*.c
				cd $(LIBFTDIR) && make

clean:
				$(RM) $(RMFLAGS) $(OBJS)
				cd $(LIBFTDIR) && make clean
fclean:			clean
				$(RM) $(RMFLAGS) $(NAME)
				cd $(LIBFTDIR) && make fclean
re:				fclean all


.PHONY:			all clean fclean re
