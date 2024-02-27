# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 14:22:59 by lhojoon           #+#    #+#              #
#    Updated: 2024/02/27 21:59:26 by lhojoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
DEBUG = 

DIR = srcs
SRCS_RAW =	main.c \
			init_main_value.c \
			push_elements.c \
			rotate_elements.c \
			reverse_rotate_elements.c \
			swap_elements.c \
			execution.c \
			check.c \
			sort_three_elements.c \
			sort_three_elements2.c \
			print_lists.c \
			error_check.c \
			error_check_2.c \
			utils.c
SRCS = $(addprefix $(DIR)/,$(SRCS_RAW))
OBJS = $(SRCS:c=o)
INCLUDES = -I./includes -I./libft

LIBFT = libft.a

all: libcompile $(OBJS) $(NAME)
$(NAME):
	$(CC) $(OBJS) $(DEBUG) -Llibft -l:libft.a -o $(NAME)
clean:
	rm $(OBJS) -f
fclean: clean libclean
	rm $(NAME) -f
re: fclean all

libcompile: libftcompile
libclean: libftclean

libftcompile:
	$(MAKE) -C libft
libftclean:
	$(MAKE) fclean -C libft

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDES) $(DEBUG)