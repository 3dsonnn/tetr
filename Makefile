# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: efinda <efinda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/23 13:08:10 by efinda            #+#    #+#              #
#    Updated: 2025/05/30 09:17:41 by efinda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tetr

SRC =	src/main.c						\
		src/init_tetr.c					\
		src/update_scenario.c			\
		src/hooks.c						\
		src/prompt_user.c				\
		src/deallocate_tetr.c			\
		src/setup/mlx.c					\
		src/setup/design.c				\
		src/setup/setup_game.c			\
		src/tile/set.c					\
		src/tile/init.c					\
		src/tile/free.c					\
		src/tile/link.c					\
		src/tile/utils.c				\
		src/tile/paint.c				\
		src/boxes_management/next.c		\
		src/boxes_management/shared.c	\
		src/boxes_management/hold.c		\
		src/boxes_management/time.c		\
		src/pieces/get_random_piece.c	\
		src/pieces/put_piece.c			\
		src/pieces/update_piece.c		\
		src/pieces/put/square.c			\
		src/pieces/put/l_mirrored.c		\
		src/pieces/put/l_shape.c		\
		src/pieces/put/tilted_z.c		\
		src/pieces/put/tilted_s.c		\
		src/pieces/put/straight.c		\
		src/pieces/put/t_shape.c		\
		src/utils.c						\

INC =	-I./inc							\
		-I./$(SUPER_LIBFT_PATH)/inc		\
		-I./$(MY_MLX_PATH)/inc			\
		-I./$(MINILIBX_PATH)			\

CC = cc
RM = rm -rf

FLAGS = -Wall -Wextra -Werror
MINILIBX_FLAGS =  -L./$(MINILIBX_PATH) -lmlx -lX11 -lXext -lm -O3

SUPER_LIBFT_PATH = Super-Libft
MY_MLX_PATH = $(SUPER_LIBFT_PATH)/my_mlx
MINILIBX_PATH = $(MY_MLX_PATH)/minilibx-linux

SUPER_LIBFT = $(SUPER_LIBFT_PATH)/libft.a
MY_MLX = $(MY_MLX_PATH)/my_mlx.a

OBJ_DIR = obj
OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

all: $(SUPER_LIBFT) $(OBJ_DIR) $(NAME)

$(NAME): $(OBJ) $(SUPER_LIBFT)
	$(CC) $(FLAGS) $(OBJ) $(MY_MLX) $(SUPER_LIBFT) $(MINILIBX_FLAGS) -o $@

$(OBJ_DIR):
	@mkdir -p $@

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) $(INC) -c $< -o $@

$(SUPER_LIBFT):
	@$(MAKE) -C $(SUPER_LIBFT_PATH)

clean:
	@$(RM) $(OBJ_DIR)
	@$(MAKE) -C $(SUPER_LIBFT_PATH) clean

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(SUPER_LIBFT_PATH) fclean

re: fclean all
	$(MAKE) -s -C $(SUPER_LIBFT_PATH) re

.PHONY: all clean fclean re
