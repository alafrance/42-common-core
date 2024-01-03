# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/23 15:02:38 by alafranc          #+#    #+#              #
#    Updated: 2021/03/31 14:36:06 by alafranc         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

FILES		= ft_lstnew_prt.c ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c  ft_itoa.c ft_memccpy.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strcmp.c \
ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strrchr.c \
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
ft_convert_base.c ft_putnbr_base.c ft_maths.c ft_maths_2.c ft_atoi_base.c ft_check_base.c \
ft_swap.c ft_strrev.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_size_nb.c \
get_next_line.c get_next_line_utils.c ft_strcpy.c \
$(addprefix ft_printf/, ft_printf.c ft_parse.c ft_display.c \
ft_print_address.c ft_print_characters.c \
ft_print_unsigned.c ft_print_decimal.c ft_putnbr_hexa.c ft_print_rate.c)

CC			= clang

OBJS 		= ${FILES:.c=.o}

OBJS_BONUS	= ${FILES_BONUS:.c=.o}

FLAGS		= -Wall -Wextra -Werror

RM			= rm -f

AR			= ar rcs

all: 	${NAME}	

%.o: %.c libft.h
			${CC} ${FLAGS} -c $< -o $@

$(NAME):	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS} ${OBJS_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY: all clean fclean re bonus
