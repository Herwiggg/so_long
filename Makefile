CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS_DIR = obj

SRCS = so_long.c parsing.c is_a_valid_map.c is_a_valid_map2.c utils.c display_map.c stock_coords.c handle_input.c exit.c utils2.c mlx_init.c player_move.c player_move2.c player_move3.c

OBJS = $(SRCS:.c=.o)

NAME = so_long

$(NAME): $(OBJS)
	@make -C libft42/
	@make -C minilibx-linux/
	$(CC) $(CFLAGS) $^ -o $@ minilibx-linux/libmlx_Linux.a libft42/libft.a get_next_line/gnl.a -lXext -lX11 -lm -lz -g3

$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

all: $(NAME)

clean:
	@make clean -C minilibx-linux/
	@make clean -C get_next_line/
	rm -f $(OBJS)

fclean: clean
	@make fclean -C libft42/
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re