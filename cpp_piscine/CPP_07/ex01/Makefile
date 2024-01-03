# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alafranc <alafranc@student.42lyon.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/23 14:11:52 by alafranc          #+#    #+#              #
#    Updated: 2021/09/30 15:06:38 by alafranc         ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME			= template

FILES			= main.cpp 

INC_FILES		= iter.hpp
INC_PATH		= .
INC				= $(addprefix ${INC_PATH}/, ${INC_FILES})

SRC_PATH		= .
SRC				= $(addprefix ${SRC_PATH}/, ${FILES})

BIN_PATH		= bin
BIN				= $(SRC:%.cpp=$(BIN_PATH)/%.o)

CC				= clang++
RM				= rm -rf
FLAGS			=  -Wall -Wextra  -Werror -std=c++98

all:  			${NAME}

init:
				@$(shell mkdir -p $(BIN_PATH))


$(BIN): $(BIN_PATH)/%.o: %.cpp ${INC}
				@mkdir -p $(@D)
				@$(CC) $(FLAGS) -c $< -o $@

${NAME}: 		init ${BIN}
				@${CC} ${FLAGS} ${BIN} -I ${INC_PATH} -o ${NAME}

clean:
				@${RM} ${BIN_PATH}			

fclean:			clean
				@${RM} ${NAME}
				
re:				fclean all
