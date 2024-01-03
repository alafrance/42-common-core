NAME=do_op
SRC=$(NAME).c
CC=gcc
FLAG=-Wall -Wextra -Werror
OPTION=-o
all: $(NAME)

clean:
	rm $(NAME) 

$(NAME):
	$(CC) $(FLAG) $(OPTION) $(NAME) $(SRC)	

fclean: clean all
