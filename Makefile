# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maadam <maadam@student.21-school.ru>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/12/04 18:21:15 by maadam            #+#    #+#              #
#    Updated: 2020/12/04 18:21:15 by maadam           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all test clean fclean re

NAME = libasm.a
HEAD = libasm.h

AC = nasm
CC = gcc

A_FLAGS = -f macho64

A_SRC = ft_strlen.s ft_strcmp.s ft_strcpy.s ft_write.s ft_read.s ft_strdup.s
C_SRC = test.c

A_OBJ = $(A_SRC:.s=.o)
C_OBJ = $(С_SCR:.c=.o)

all: $(NAME)

$(NAME): $(A_OBJ)
	@ar rc $(NAME) $?
	@ranlib $(NAME)
	@echo "$(NAME) is ready!"

%.o: %.s
	@$(AC) $(A_FLAGS) $<

test:
	@$(CC) $(C_SRC) $(NAME)
	@echo "$(NAME) is ready to test!\n"
	@./a.out

clean:
	@rm -f $(A_OBJ)
	@rm -f $(C_OBJ)
	@rm -f ./a.out
	@echo "OBJ removed"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) removed"

re: fclean all