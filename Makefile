NAME		= so_long
CFLAGS		= -Wall -Wextra -Werror
INCLUDES 	= -I/usr/include -Imlx
MLX_FLAGS 	= -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_DIR 	= ./minilibx-linux
MLX_LIB 	= $(MLX_DIR)/libmlx_Linux.a
LIBFT_DIR	= ./libft42
LIBFT_LIB	= $(LIBFT_DIR)/libft.a
GNL_DIR 	= ./get_next_line
GNL_LIB		= $(GNL_DIR)/gnl.a
SRCS 		=	so_long.c parsing.c is_a_valid_map.c is_a_valid_map2.c utils.c display_map.c stock_coords.c handle_input.c exit.c utils2.c mlx_init.c player_move.c player_move2.c player_move3.c
OBJS 		= $(SRCS:.c=.o)

all: $(MLX_LIB) $(LIBFT_LIB) $(GNL_DIR) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT_LIB) $(GNL_LIB) 

$(MLX_LIB):
	@make -C $(MLX_DIR)

$(LIBFT_LIB): 
	@make -C $(LIBFT_DIR)

$(GNL_LIB): 
	@make -C $(GNL_DIR)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: clean all