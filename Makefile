# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atahiri <atahiri@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/02 12:01:48 by atahiri           #+#    #+#              #
#    Updated: 2021/01/06 09:09:29 by atahiri          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

SRCS = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s
OBJS = $(SRCS:.s=.o)
FLAGS = -Wall -Werror -Wextra
NA = nasm
TEST = test
NA_FLAGS =  -f macho64

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

all:	$(NAME)

clean:
				rm -rf $(OBJS)

fclean:			clean
				rm -rf $(NAME) $(TEST)

re:				fclean $(NAME)

test:			$(NAME)
				gcc $(FLAGS) -L. -lasm -o $(TEST) main.c
				./$(TEST) < Makefile
