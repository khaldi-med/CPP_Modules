# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mohkhald <mohkhald@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/08 05:12:44 by mohkhald          #+#    #+#              #
#    Updated: 2026/04/16 21:36:23 by mohkhald         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = person

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp myClass.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
