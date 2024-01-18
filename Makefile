NAME=fdf

CC=gcc
CFLAGS= -Wall -Wextra -Werror -g3 -fsanitize=address
CPPFLAGS= -lglfw

LIBS_DIR=./libs
SRC_DIR=./src

all: $(NAME)

DO_LIBS:
	@echo DOING LIBS
	@make -C $(LIBS_DIR) all

DO_SRC:
	@echo DOING SRC
	make -C $(SRC_DIR) all

$(NAME): | DO_SRC DO_LIBS
	@echo LINKING
	$(CC) -L$(LIBS_DIR) -lft -lmlx42 -L$(SRC_DIR) -lfdf $(CFLAGS) $(CPPFLAGS) -o $@

clean:
	@make -C $(LIBS_DIR) clean
	@make -C $(SRC_DIR) clean

fclean: clean
	@make -C $(LIBS_DIR) fclean
	@make -C $(SRC_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
