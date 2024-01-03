FLAG=-Wall -Wextra -Werror
OBJS=srcs/*.o includes/*.h.gch
SRCS=srcs/*.c includes/*.h
O=*.o
OPTION=-c
RM=rm -f
CC=gcc
NAME=libft.a
AR=ar rc
all: $(NAME) LIB

$(NAME):
	$(CC) $(FLAG) $(OPTION) $(SRCS) && mv *.o srcs/.
			
LIB:
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all
