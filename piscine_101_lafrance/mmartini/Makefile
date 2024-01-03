CC		:	cc
NAME	:	bsq
FLAG	:	-Wall -Wextra -Werror
SRCS		: 	sources/*.c
OBJS	:	$(SRCS:.c =.o)
O		:	*.o
RM		:	rm -f

$(NAME)	:	$(CC) $(FLAG) -o $(NAME) $(OBJS) 

all		:	$(NAME) 

clean	:	$(RM) $(O)

fclean	:	$(CLEAN)
			$(RM) $(ALL)
			
