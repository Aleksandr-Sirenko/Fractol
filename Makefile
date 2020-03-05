# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asirenko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/21 17:19:16 by asirenko          #+#    #+#              #
#    Updated: 2019/02/01 20:24:34 by asirenko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_DIR = ./src/
OBJ_DIR = ./
INC_DIR = ./inc/
LIB_DIR = ./lib/

SRC = fractol.c colors.c keys.c keys2.c fractals.c init.c colors2.c keys3.c \
	usage.c

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

CC = gcc -Wall -Wextra -Werror -O2

FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = $(LIB_DIR)libft/
LIBFT = $(LIBFT_DIR)libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@$(CC) $(LIBFT) $(OBJ) $(FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: %.c
	$(CC) -c $< -o $@ -I $(INC_DIR)

clean:
	rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)
fclean: clean
	rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all

vpath %.c $(SRC_DIR)
