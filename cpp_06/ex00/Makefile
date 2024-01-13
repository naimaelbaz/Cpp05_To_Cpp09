# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/12 18:05:13 by nel-baz           #+#    #+#              #
#    Updated: 2024/01/12 18:05:49 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Convert

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	ScalarConverter.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp ScalarConverter.hpp
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