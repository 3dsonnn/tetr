# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 13:08:10 by efinda            #+#    #+#              #
#    Updated: 2025/05/24 14:01:55 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tetr

SRC =	src/main.c				\
		src/init_tetr.c			\
		src/deallocate_tetr.c	\
		src/tile/set.c			\
		src/tile/init.c			\
		src/tile/free.c			\
		src/tile/link.c			\
		src/tile/utils.c		\

CC = cc
RM = rm -rf
FLAGS =  -I./$(MLXPATH) -O3

MY_MLXPATH = my_mlx
MY_MLX = $(MY_MLXPATH)/my_mlx.a

LIBFTPATH = my_mlx/Super-Libft
LIBFT =	$(LIBFTPATH)/libft.a

MLXPATH = my_mlx/minilibx-linux
MLX = $(MLXPATH)/libmlx.a
LIBS =	-L./$(MLXPATH) -lmlx -lX11 -lXext -lm

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(MY_MLX) $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(FLAGS) $(OBJ) $(MY_MLX) $(LIBFT) $(LIBS) -o $@

$(MY_MLX):
	@$(MAKE) -C $(MY_MLXPATH)

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(MY_MLXPATH) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(MY_MLXPATH) fclean

re: fclean all
	$(MAKE) -s -C $(MY_MLXPATH) re

.PHONY: all clean fclean re
