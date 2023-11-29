# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhojoon <lhojoon@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/28 14:22:59 by lhojoon           #+#    #+#              #
#    Updated: 2023/11/29 18:07:53 by lhojoon          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

DIR = srcs
SRCS_RAW =	main.c \
			init_main_value.c \
			push_elements.c \
			rotate_elements.c \
			reverse_rotate_elements.c \
			swap_elements.c \
			execution.c \
			check.c \
			get_cost.c
SRCS = $(addprefix $(DIR)/,$(SRCS_RAW))
OBJS = $(SRCS:c=o)
INCLUDES = -I./includes -I./libft

LIBFT = libft.a

all: $(NAME)
$(NAME): libcompile $(OBJS)
	$(CC) $(OBJS) $(DEBUG) -Llibft -l:libft.a -o $(NAME)
clean:
	rm $(OBJS) $(OBJB) -f
fclean: clean libclean
	rm $(NAME) -f
re: fclean all

libcompile: libftcompile
libclean: libftclean

libftcompile:
	$(MAKE) bonus -C libft
libftclean:
	$(MAKE) fclean -C libft

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS) $(INCLUDES) $(DEBUG)