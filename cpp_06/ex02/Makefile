# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 16:51:11 by nel-baz           #+#    #+#              #
#    Updated: 2024/01/13 16:52:59 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Base

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS =	Base.cpp A.cpp B.cpp C.cpp main.cpp functions.cpp

OBJS = $(SRCS:.cpp=.o)

%.o: %.cpp Base.hpp A.hpp B.hpp C.hpp
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