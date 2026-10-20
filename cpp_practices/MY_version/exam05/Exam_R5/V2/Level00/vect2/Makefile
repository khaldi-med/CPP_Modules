NAME = vect2
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp vect2.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@cat subject.txt

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
