
NAME			=	libft.a

FILES_PRINTF	=	ft_printf.c ft_parse.c ft_display.c \
					ft_print_address.c ft_print_characters.c \
					ft_print_unsigned.c ft_print_decimal.c ft_putnbr_hexa.c ft_print_rate.c
					
FILES			= 	ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
					ft_isprint.c  ft_itoa.c ft_memccpy.c ft_memcpy.c ft_memchr.c ft_memcmp.c ft_memmove.c ft_memset.c \
					ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c \
					ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strcmp.c \
					ft_strncmp.c ft_strnstr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c ft_strrchr.c \
					ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
					ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c \
					ft_convert_base.c ft_putnbr_base.c ft_maths.c ft_maths_2.c ft_atoi_base.c ft_check_base.c \
					ft_swap.c ft_strrev.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_size_nb.c \
					get_next_line.c get_next_line_utils.c ft_strcpy.c ft_strs.c ft_lst_remove_if.c ft_strsjoin_before.c \
					$(addprefix ft_printf/, ${FILES_PRINTF})


BIN_PATH		=	bin
BIN 			=	$(FILES:%.c=$(BIN_PATH)/%.o)

FLAGS			= 	-Wall -Wextra -Werror
RM				=	rm -rf
AR				=	ar rcs
CC				=	clang


all: 				${NAME}

$(BIN): 			$(BIN_PATH)/%.o: %.c libft.h
					@mkdir -p $(@D)
					@$(CC) $(FLAGS) -o $@ -c $<
					@printf "\e[?25l\e[JLIBFT : \e[92m$(notdir $<)\e[0m\r"

$(NAME):			init ${BIN}
					@${AR} ${NAME} ${BIN}
					@printf '\033[?25l\033[JLIBFT CREATED \033[92m✔ \033[0m\033[?25h\n'

init:
					@${shell mkdir -p ${BIN_PATH}}
clean:
					@${RM} ${BIN_PATH}
					@printf '\033[?25l\033[JLIBFT DELETED \033[92m✔ \033[0m\033[?25h\n'

fclean:				clean
					@${RM} ${NAME}

re:					fclean all

.PHONY: all clean fclean re bonus
