CC=cc
FLAGS=-Wall -Werror -Wextra
INCLUDES=mlx/mlx.h
# LIBS=mlx/libmlx.dylib
SRCS=
OBJS=$(SRCS:.c=.o)
NAME=so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBMLX)
	$(CC) $(FLAGS) $(OBJS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -I$(INCLUDES) -c $^ -o $@


clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
