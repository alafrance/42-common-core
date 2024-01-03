ME         =     rush-02
FLAG       =     -Wall -Wextra -Werror
OPTION     =     -c
SRCS       =     *.c
OBJS       =     $(SRCS:.c=.o)

all        :     $(NAME)

$(NAME)    :
	          $(CC) $(FLAG) $(OPTION) $(SRCS)
			  $(CC) $(FLAG) -o $(NAME) $(OBJS)

clean    :
	          /bin/rm -f $(OBJS)

fclean    :    clean
	          /bin/rm -f $(NAME)

re        :    fclean algg=
