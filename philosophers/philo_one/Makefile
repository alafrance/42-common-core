# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/21 10:23:43 by alafranc          #+#    #+#              #
#    Updated: 2021/06/30 17:04:55 by alafranc         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			= philo_one

FILES			= main.c ft_error.c philo.c ft_utility.c init_struct.c

INC_FILES		= philo_one.h

OBJS_PATH		= objs
OBJS 			= ${addprefix ${OBJS_PATH}/,$(FILES:.c=.o)}

CC				= clang
RM				= rm -rf
FLAGS			= -Wall -Wextra -Werror

all: 			${NAME}


init:
				$(shell mkdir -p $(OBJS_PATH))

$(OBJS_PATH)/%.o : %.c  $(INC_FILES)
				@$(CC) $(FLAGS) -I. -c $< -o $@
				
${NAME}: 		init ${OBJS}
				@${CC} ${FLAGS} ${OBJS} -o ${NAME} -I.
				@printf '\033[?25l\033[JPHILOSOPHERS CREATED \033[92m✔ \033[0m\033[?25h\n'

clean:
				@printf '\033[?25l\033[JPHILOSOPHERS DELETED \033[92m✔ \033[0m\033[?25h\n'
				@${RM} ${OBJS_PATH}

fclean:			clean
				@${RM} ${NAME}

re:				fclean all


.PHONY: all clean fclean re bonus lib