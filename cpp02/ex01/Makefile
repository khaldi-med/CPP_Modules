# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/05 22:24:23 by mohkhald          #+#    #+#              #
#    Updated: 2026/04/06 02:53:15 by mohkhald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = ex01
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98
SRCS        = main.cpp Fixed.cpp
OBJS        = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS) Fixed.hpp
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
