# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/13 22:09:07 by mohkhald          #+#    #+#              #
#    Updated: 2026/03/13 23:05:25 by mohkhald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME=	zombie

CXX = c++

CXXFLAGS=	-Wall -Wextra -Werror -std=c++98

SRCS=	main.cpp randomChump.cpp \
		Zombie.cpp randomChump.cpp \
		newZombie.cpp 
      
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) Zombie.hpp
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
