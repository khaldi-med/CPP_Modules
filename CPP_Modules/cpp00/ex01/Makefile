# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: student <student@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/09 00:00:00 by student           #+#    #+#              #
#    Updated: 2026/03/09 00:00:00 by student          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	phonebook

CXX		=	c++
CXXFLAGS=	-Wall -Wextra -Werror -std=c++98

SRCS	=	main.cpp \
			Contact.cpp \
			PhoneBook.cpp
OBJS	=	$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
