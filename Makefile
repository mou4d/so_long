CC=cc
FLAGS=-Wall -Werror -Wextra
# INCLUDES=mlx/mlx.h
INCLUDES=
# LIBS=mlx/libmlx.dylib
SRCS=main.c helpers.c handlers.c map.c  map2.c movements.c
OBJS=$(SRCS:%.c=%.o)
NAME=so_long
LIBFT=./libft/libft.a
FTPRINTF=./ftprintf/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT) $(FTPRINTF) $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit $(LIBFT) $(FTPRINTF) -fsanitize=address -g -o $(NAME)

%.o: %.c 
	$(CC) $(FLAGS) $(INCLUDES) -c $^ -o $@

$(LIBFT):
	make -C ./libft

$(FTPRINTF):
	make -C ./ftprintf

clean:
	rm -f $(OBJS)
	make clean -C ./libft
	make clean -C ./ftprintf

fclean: clean
	rm -f $(NAME)
	make fclean -C ./libft
	make fclean -C ./ftprintf
