# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liaydiny <liaydiny@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/17 00:09:39 by liaydiny          #+#    #+#              #
#    Updated: 2023/02/17 23:34:44 by liaydiny         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror 

ARCHIVE = ar -r

CC = cc

SRCS = $(wildcard *.c)
	
all: $(NAME)

OBJS = $(SRCS:.c=.o)

%.o :%.c
	$(CC) $(CFLAGS) -c $< -o $@ 
$(NAME): $(OBJS)
	@$(ARCHIVE) $(NAME) $(OBJS) 

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
