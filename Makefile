# Variables
NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = src
OBJ_DIR = obj
SRC_FILES = main.c start_game.c parse_map1.c parse_map2.c parse_map3.c parse_map4.c \
			init_key.c init.c key.c key_1.c init_image.c utils.c utils_1.c  free2.c \
			load_texture.c check_map1.c check_map2.c check_map3.c check_map4.c \
			create_image1.c create_image2.c create_image3.c create_image4.c free1.c \


OBJS = $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
LIBFT_DIR = libs/libft
LIBMLX_DIR = libs/mlx-linux
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX = $(LIBMLX_DIR)/libmlx_linux.a
INCLUDES = -I$(SRC_DIR) -I$(LIBFT_DIR) -I$(LIBMLX_DIR)
CPPFLAGS = -Ilibs/libft/headers -Ilibs/mlx-linux
LDFLAGS = -Llibs/mlx-linux -Llibs/libft
MLXFLAG = -lft -lmlx -lXext -lX11 -lm

# Colors
RED = \033[0;31m
ORANGE = \033[38;5;208m
YELLOW = \033[0;33m
GREEN = \033[0;32m
BLUE = \033[0;34m
RESET = \033[0m

# Targets
all: $(NAME)

$(LIBFT):
	@echo "$(YELLOW)Compiling libft..."
	$(MAKE) -C $(LIBFT_DIR)

$(LIBMLX):
	@echo "$(BLUE)Compiling libmlx..."
	$(MAKE) -C $(LIBMLX_DIR)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	@echo "$(GREEN)Linking $@..."
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJS) -L$(LIBFT_DIR) -L$(LIBMLX_DIR) -lft $(LDFLAGS) $(MLXFLAG) -o $(NAME)
	@echo "$(GREEN)$@ is ready!$(RESET)"

# Compilation rules
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(ORANGE)Compiling $<..."
	$(CC) $(CFLAGS) $(CPPFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "$(RED)Cleaning object files..."
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@$(MAKE) -C $(LIBMLX_DIR) clean

fclean: clean
	@echo "$(RED)Cleaning executables..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_DIR)/libft.a
	@rm -f $(LIBMLX_DIR)/libmlx_linux.a
	@rm -f $(LIBMLX_DIR)/libmlx.a

re: fclean all

.PHONY: all clean fclean re $(LIBFT) $(LIBMLX)

