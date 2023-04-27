# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zdogan <zdogan@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 18:37:48 by sena              #+#    #+#              #
#    Updated: 2023/04/27 16:07:44 by zdogan           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGSS = -Wall -Wextra -Werror
SRCS = commands.c arg.c push_swap.c selection_sort.c utils.c radix.c single_sort.c
OBJS = $(SRCS:.c=.o)
NAME = push_swap
CC = gcc
LIB = ./ft_printf/libftprintf.a

all: $(NAME)

$(NAME) : $(LIB)  $(OBJS)
	gcc $(OBJS) ./ft_printf/libftprintf.a -o $(NAME)

$(LIB) :
	@make -C ft_printf/
	@echo "libft compiled."

.c.o:
	$(CC) $(CFLAGSS) -c $< -o $@

clean:
	make clean -C ft_printf/
	rm -rf $(OBJS)

fclean: clean
	make fclean -C ft_printf/
	rm -rf $(NAME)

re: fclean all

norm:
	@norminette *.[ch]

.PHONY: clean re