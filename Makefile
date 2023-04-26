CC=cc
FLAGS=-Wall -Werror -Wextra
# INCLUDES=mlx/mlx.h
INCLUDES=
# LIBS=mlx/libmlx.dylib
SRCS=main.c
OBJS=$(SRCS:%.c=%.o)
NAME=so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $^ -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
