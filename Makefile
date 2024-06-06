CC = cc

FLAGS = -Wall -Wextra -Werror

INCLUDE = -Iinc/ -Imlx/

MLX = mlx/libmlx_Linux.a -L mlx -lXext -lX11

SRCS = src/main.c \
		src/list_utils.c \
		src/parsing.c \
		src/utils.c \
		src/solver.c \
		src/maths_utils.c \
		src/window.c

OBJS_BASE = $(SRCS:.c=.o)

OBJS = $(addprefix obj/,$(OBJS_BASE))

NAME = computor

all: obj $(NAME)

obj :
	mkdir -p obj
	mkdir -p obj/src

$(NAME) : $(OBJS)
	@echo "\n"
	@echo "\033[0;32mCompiling computorv1..."
	$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(INCLUDE) $(MLX)
	@echo "\n\033[0mDone !"

obj/%.o : %.c
	@printf "\033[0;33mGenerating computorv1 objects... %-33.33s\r" $@
	$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	make clean -C mlx/
	@echo "\033[0;31m"
	@echo "\nRemoving binaries..."
	rm -f $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[0;31m\nDeleting executable..."
	rm -f $(NAME)
	@echo "\033[0m"

re: fclean obj $(NAME)

.PHONY: all clean fclean re
