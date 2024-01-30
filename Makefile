NAME		= so_long
CFLAGS		= -Wextra
INCLUDES 	= -I/usr/include -Imlx
MLX_FLAGS 	= -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11
MLX_DIR 	= ./minilibx-linux
MLX_LIB 	= $(MLX_DIR)/libmlx_Linux.a
SRCS = so_long.c
OBJS = $(SRCS:.c=.o)

all: $(MLX_LIB) $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)

$(MLX_LIB):
	@make -C $(MLX_DIR)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)


re: clean all