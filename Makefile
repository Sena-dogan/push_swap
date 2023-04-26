# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sena <sena@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/22 18:37:48 by sena              #+#    #+#              #
#    Updated: 2023/04/23 15:59:51 by sena             ###   ########.fr        #
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
	rm -rf $(OBJS) $(NAME)

fclean: clean
	make fclean -C ft_printf/
	make fclean -C ft_printf/libft/	

re: fclean all

norm:
	@norminette *.[ch]

.PHONY: clean re