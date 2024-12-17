NAME = fdf
LIB = libft.a
LIB_DIR = libft
MLX_DIR = mlx_linux
SRC_RW = render_window
SRC_PRS = parsing
SRC_MAP = create_map
SRC_TEST = test
SRC_UTILS = utils
SRC_CLR = color
SRC_FREE = free
SRC_HKS = hooks
SRC_PRJ = projections

SRC = main.c \
	$(SRC_RW)/init_render.c \
	$(SRC_RW)/make_pixel.c \
	$(SRC_RW)/rotate.c \
	$(SRC_PRS)/parsing.c \
	$(SRC_MAP)/create_map.c \
	$(SRC_UTILS)/ft_split_scam.c \
	$(SRC_RW)/make_render_plus.c \
	$(SRC_TEST)/testing.c \
	$(SRC_CLR)/color.c \
	$(SRC_CLR)/interpolate.c \
	$(SRC_FREE)/free.c \
	$(SRC_HKS)/scale_hook.c \
	$(SRC_HKS)/rotate_hook.c \
	$(SRC_HKS)/zoom_n_high.c \
	$(SRC_HKS)/reset_hook.c \
	$(SRC_HKS)/projection_hook.c \
	$(SRC_PRJ)/projection_x.c \
	$(SRC_PRJ)/projection_y.c \
	$(SRC_UTILS)/hexa_to_int_scam.c \
	# $(SRC_RW)/make_render.c \

OBJ_DIR = obj

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror
GREEN = \033[0;32m
CYAN = \033[0;36m
RESET = \033[0m
GRAY = \033[90m

SUCCESS = $(GREEN)[SUCCESS]$(RESET)
INFO = $(CYAN)[INFO]$(RESET)

all : $(NAME)

$(OBJ_DIR):
	@if [ ! -d $(OBJ_DIR) ]; then \
		echo "$(INFO) create $(OBJ_DIR)....$(GRAY)"; \
		mkdir -p $(OBJ_DIR); \
		echo "$(SUCCESS) $(OBJ_DIR) done !"; \
	fi

$(MLX_DIR):
	@if [ -d ./$(MLX_DIR) ]; then \
		echo "$(INFO) $(MLX_DIR) already exist"; \
	else \
		echo "$(INFO) git clone minilibx in directory mmlx_linux"; \
		git clone https://github.com/42Paris/minilibx-linux.git $(MLX_DIR); \
		echo "$(INFO) Configure minilibx...$(GRAY)"; \
		cd $(MLX_DIR) && ./configure && cd ..; \
		echo "$(SUCCESS) minilibx done"; \
	fi

$(LIB):
	@if [ -d ./$(LIB_DIR) ]; then \
		echo "$(INFO) $(LIB_DIR) already exist"; \
	else \
		echo "$(INFO) git clone Polybft in directory libft"; \
		git clone https://github.com/Polybiuss/libft.git $(LIB_DIR); \
		echo "$(INFO) Make $(LIB)..$(GRAY)"; \
		make -sC $(LIB_DIR); \
		echo "$(SUCCESS) Make done!"; \
	fi

$(OBJ_DIR)/%.o: %.c | $(LIB) $(MLX_DIR) 
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB_DIR)/$(LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# $(NAME): $(OBJ)
#	 $(CC) $^ $(LIB_DIR)/$(LIB) -lm -lXext -lX11 mlx_linux/libmlx.a -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(LIB_DIR)
	rm -rf $(MLX_DIR)

fclean: clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re