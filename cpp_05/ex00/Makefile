NAME = Bureaucrat

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Bureaucrat.cpp main.cpp GradeTooHighException.cpp GradeTooLowException.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp Bureaucrat.hpp GradeTooHighException.hpp GradeTooLowException.hpp
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME) $(OBJS)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:	
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re : fclean all

.PHONY: clean