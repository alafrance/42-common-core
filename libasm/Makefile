NAME		= libasm
LIB			= libasm.a
NASM		= nasm 
CFLAGS		= #-Wall -Wextra -Werror
NFLAGS		= -f macho64
OBJS		= ${FILES:.s=.o}
FILES		= ft_read.s ft_strcmp.s ft_strcpy.s ft_strdup.s ft_strlen.s ft_write.s
RM			= rm -f
CC			= clang
AR			= ar -rcs

all: 		${NAME}

%.o:      %.s   libasm.h
			${NASM} ${NFLAGS} $<

${NAME}:	${OBJS}
			${AR} ${LIB} ${OBJS}
main:		${NAME}
			${CC} ${CFLAGS} -o ${NAME} ${LIB} main.c
clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${LIB}
			${RM} ${NAME}

re : 		fclean all

.PHONY: 	all clean fclean re
