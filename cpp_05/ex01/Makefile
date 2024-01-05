NAME = Bureaucrat

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	main.cpp \
		Bureaucrat.cpp \
		GradeTooHighException.cpp \
		GradeTooLowException.cpp \
		GradeTooHighException_Form.cpp \
		GradeTooLowException_Form.cpp \
		Form.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp Bureaucrat.hpp GradeTooHighException.hpp GradeTooLowException.hpp Form.hpp GradeTooHighException_Form.hpp GradeTooLowException_Form.hpp
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