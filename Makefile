NAME = fractol

FLAGS = -Wall -Werror -Wextra
XFLAGS = -framework OpenGL -framework AppKit

HEADER_LIST = fractol.h\


SRC_LIST = fractol.c\


HEADERS = $(addprefix $(SRC_DIR), $(HEADER_LIST))
SRC = $(addprefix $(SRC_DIR), $(SRC_LIST))
SRC_DIR = ./src/
OBJ = $(addprefix $(OBJ_DIR), $(SRC_LIST:.c=.o))
OBJ_DIR = ./obj/

LIBFT = $(LIBFT_DIR)libft.a
LIBFT_DIR = ./libft/

LIBX = $(LIBX_DIR)libmlx.a
LIBX_DIR = ./minilibx_macos/

all: $(NAME)

$(NAME): $(LIBFT) $(LIBX) $(OBJ_DIR) $(OBJ)
	@gcc $(OBJ) $(LIBFT) $(LIBX) $(FLAGS) $(XFLAGS) -o $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c  $(HEADERS)
	@gcc -c $< -o $@ $(FLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

$(LIBX):
	@make -C $(LIBX_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean
	@make -C $(LIBX_DIR) clean

fclean: clean
	@rm -f $(NAME) $(LIBFT) $(LIBX)

re: fclean all