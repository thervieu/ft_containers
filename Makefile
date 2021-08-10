# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/29 20:38:55 by user42            #+#    #+#              #
#    Updated: 2021/08/10 15:40:08 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	exec_tester

SRCS =	main.cpp			\
		list_tests.cpp		\
		vector_tests.cpp	\
		map_tests.cpp		\
		stack_tests.cpp		\
		queue_tests.cpp

SRCS_DIR = ./srcs/

INCS = ./incs/tests.hpp

FLAGS =	-Wall -Wextra -Werror -std=c++98

OBJ = $(SRCS:.cpp=.o)

OBJS = $(addprefix $(OBJS_DIR),  $(OBJ))

OBJS_DIR =	objs/

$(OBJS_DIR)%.o: $(SRCS_DIR)%.cpp $(INCS)
	@mkdir -p $(OBJS_DIR)
	@clang++ $(FLAGS) -c  $< -o $@
	@echo "Compiling $<"

$(NAME): $(OBJS)
	@clang++ $(FLAGS) -o $(NAME) $(OBJS)
	@echo "Exec created"

all: $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@echo "Objects removed"

fclean: clean
	@rm -f $(NAME)
	@echo "Exec removed"

re: fclean all

run: all
	@./$(NAME)

list: all
	@./$(NAME) list

vector: all
	@./$(NAME) vector

map: all
	@./$(NAME) map

stack: all
	@./$(NAME) stack

queue: all
	@./$(NAME) queue