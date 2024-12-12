NAME = fdf
LIB = libft.a
LIB_DIR = libft
SRC_RW = render_window
SRC_PRS = parsing
SRC_MAP = create_map
SRC_TEST = test
SRC_UTILS = utils

SRC = main.c \
	$(SRC_RW)/init_render.c \
	$(SRC_RW)/make_pixel.c \
	$(SRC_RW)/make_render.c \
	$(SRC_PRS)/parsing.c \
	$(SRC_MAP)/create_map.c \
	$(SRC_TEST)/testing.c \
	$(SRC_UTILS)/ft_split_scam.c \
	$(SRC_RW)/make_render_plus.c \

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
	if [ ! -d $(OBJ_DIR) ]; then \
		mkdir -p $(OBJ_DIR); \
	fi

$(LIB):
	@if [ -d ./$(LIB_DIR) ]; then \
		echo "$(INFO) $(LIB_DIR) && git pull"; \
		cd $(LIB_DIR) && git pull && cd ..; \
	else \
		echo "$(INFO) git clone Polybft in directory libft"; \
		git clone https://github.com/Polybiuss/libft.git $(LIB_DIR); \
	fi
	@echo "$(INFO) Make $(LIB)..$(GRAY)"
	make -sC $(LIB_DIR)
	@echo "$(SUCCESS) Make done!"

$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR) $(LIB)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIB_DIR)/$(LIB) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

# $(NAME): $(OBJ)
#	 $(CC) $^ $(LIB_DIR)/$(LIB) -lm -lXext -lX11 mlx_linux/libmlx.a -o $(NAME)

clean:
	rm -rf $(OBJ_DIR)
	make clean -sC $(LIB_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -sC $(LIB_DIR)

re : fclean all

.PHONY : all clean fclean re