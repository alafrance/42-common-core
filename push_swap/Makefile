# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 14:11:52 by alafranc          #+#    #+#              #
#    Updated: 2021/04/20 13:48:03 by alafranc         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

PUSH			= push_swap

CHECKER			= checker

FILES_GENERAL	= display.c display_utility.c parse_number.c ft_error.c ft_garbage_collector.c\
					$(addprefix instructions/, push.c reverse.c rotate.c swap.c) \
					ft_lst_is_sort.c 
FILES_PUSH		= push_swap.c main_push.c algo_sort.c algo_sort_5.c algo_sort_3.c reference_tab.c \
					find_number.c
FILES_CHECK		= main.c checker.c array_instruction.c

GEN_PATH		= general/
PUSH_PATH		= push_swap/
CHECK_PATH		= checker/
INC_FILES		= push_swap.h general.h checker.h
INC_PATH		= ./includes/
INC				= $(addprefix ${INC_PATH}, ${INC_FILES})

SRC_PATH		= srcs
SRC				= $(addprefix ${SRC_PATH}/, $(addprefix ${PUSH_PATH}, ${FILES_PUSH}) $(addprefix ${GEN_PATH}, ${FILES_GENERAL}))
SRC_2			= $(addprefix ${SRC_PATH}/, $(addprefix ${CHECK_PATH}, ${FILES_CHECK}) $(addprefix ${GEN_PATH}, ${FILES_GENERAL}))

CC				= clang
RM				= rm -rf
OBJS_PATH		= objs_push_swap
OBJS 			= $(addprefix $(OBJS_PATH)/, $(notdir $(SRC:.c=.o)))

OBJS_PATH_2		= objs_checker
OBJS_2 			= $(addprefix $(OBJS_PATH_2)/, $(notdir $(SRC_2:.c=.o)))
FLAGS			= -Wall -Wextra -Werror

#LIBRARY
NAME_LIBFT 		= libft.a
LIBFT_PATH 		= libft/
LIBFT			= $(addprefix ${LIBFT_PATH}, ${NAME_LIBFT})

all: 			${PUSH}	${CHECKER}


init:
				$(shell mkdir -p $(OBJS_PATH))
				$(shell mkdir -p $(OBJS_PATH_2))
lib: 
				make -C ${LIBFT_PATH}
				cp ${LIBFT} .

$(OBJS_PATH)/%.o : $(SRC_PATH)/*/*/%.c  $(INC)
				$(CC) $(FLAGS) -I ${INC_PATH} -c $< -o $@

$(OBJS_PATH)/%.o : $(SRC_PATH)/*/%.c  $(INC)
				$(CC) $(FLAGS) -I ${INC_PATH} -c $< -o $@
				
$(OBJS_PATH_2)/%.o : $(SRC_PATH)/*/%.c  $(INC)
				$(CC) $(FLAGS) -I ${INC_PATH} -c $< -o $@

$(OBJS_PATH_2)/%.o : $(SRC_PATH)/*/*/%.c  $(INC)
				$(CC) $(FLAGS) -I ${INC_PATH} -c $< -o $@

${PUSH}: 		init lib ${OBJS}
				${CC} ${FLAGS} ${OBJS} -o ${PUSH} ${NAME_LIBFT} -I ${INC_PATH}

${CHECKER}:		init lib ${OBJS_2}
				${CC} ${FLAGS} ${OBJS_2} -o ${CHECKER} ${NAME_LIBFT} -I ${INC_PATH}

clean:
				make -C ${LIBFT_PATH} clean
				${RM} ${OBJS_PATH} ${OBJS_PATH_2}

fclean:			clean
				${RM} ${PUSH}
				${RM} ${CHECKER}
				${RM} ${LIBFT}
				${RM} ${NAME_LIBFT}
re:				fclean all


.PHONY: all clean fclean re bonus lib