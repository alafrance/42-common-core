FLAG	:	-Wall -Wextra -Werror
OBJS	:	$(SRCS:.c=.o)
SRCS	:	srcs/*.c includes/*.h
O		:	*.o
OPTION	:	-c
RM		:	rm -f
CC		: 	gcc
NAME	:   libft.a	

all		:	$(NAME)
			$(LIB)

$(NAME)	:	$(CC) $(FLAG) $(OPTION) $(SRCS)
			
$(LIB)	:	$(AR) $(NAME) $(O)
clean	:
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		: fclean all

