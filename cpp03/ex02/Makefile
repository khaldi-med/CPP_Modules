# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohaouar <mohaouar@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/01 15:03:16 by mohaouar          #+#    #+#              #
#    Updated: 2026/04/08 02:41:40 by mohaouar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = claptrap
CC          = c++
FLAGS       = -Wall -Wextra -Werror -std=c++98
SRC         = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp
OBJ         = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all