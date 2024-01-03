NAME			= ft_containers


FILES_TESTER	= SetTest.cpp MapTest.cpp displayTest.cpp StackTest.cpp googleTestLike.cpp VectorTest.cpp
FILES			= main.cpp $(addprefix tester/, ${FILES_TESTER})


INC_CONTAINER	= map.hpp stack.hpp vector.hpp set.hpp
INC_ITERATOR	= bidirectional_iterator_map.hpp bidirectional_iterator_set.hpp iterator.hpp random_access_iterator.hpp
INC_TESTER		= tester.hpp
INC_FILES		= $(addprefix containers/, ${INC_CONTAINER}) \
					$(addprefix iterator/, ${INC_ITERATOR})\
					$(addprefix tester/, ${INC_TESTER})\
					RedNWARTree.hpp pair.hpp metafunctions.hpp utility.hpp


INC_PATH		= .
INC				= $(addprefix ${INC_PATH}/, ${INC_FILES})

SRC_PATH		= .
SRC				= $(addprefix ${SRC_PATH}/, ${FILES})

BIN_PATH		= bin
BIN 			= $(SRC:%.cpp=$(BIN_PATH)/%.o)

CC				= clang++
RM				= rm -rf
FLAGS			= -std=c++98 -Wall -Wextra  -Werror #-fsanitize=address -g3

all: 			${NAME}

init:
				@$(shell sed -i -e 's/namespace library = std;/namespace library = ft;/' tester/tester.hpp)
				@${RM} tester/tester.hpp-e
				@$(shell mkdir -p $(BIN_PATH))
init_std:
				@$(shell sed -i -e 's/namespace library = ft;/namespace library = std;/' tester/tester.hpp)
				@${RM} tester/tester.hpp-e
				@$(shell mkdir -p $(BIN_PATH))

$(BIN): $(BIN_PATH)/%.o: %.cpp ${INC}
				@mkdir -p $(@D)
				@$(CC) $(FLAGS) -I ${INC_PATH} -o $@ -c $<
				@printf "\e[?25l\e[J $(NAME) : \e[92m$(notdir $<)\e[0m\r"

${NAME}: 		init ${BIN}
				@${CC} ${FLAGS} ${BIN} -o ${NAME} -I ${INC_PATH}
				@printf '\033[?25l\033[J$(NAME) \033[92m✔ \033[0m\033[?25h\n'

std:			init_std ${BIN}
				@${CC} ${FLAGS} ${BIN} -o std_containers -I ${INC_PATH}
				@printf '\033[?25l\033[J$(NAME) \033[92m✔ \033[0m\033[?25h\n'
clean:
				@${RM} ${BIN_PATH}
				@printf '\033[?25l\033[J$(NAME) DELETED \033[92m✔ \033[0m\033[?25h\n'

fclean:
				@${RM} ${BIN_PATH}
				@${RM} ${NAME}
				@printf '\033[?25l\033[J$(NAME) DELETED \033[92m✔ \033[0m\033[?25h\n'

re:				fclean all

.PHONY: all clean fclean re bonus init

