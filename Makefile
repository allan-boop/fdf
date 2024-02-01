#########################################
## ARGUMENTS
#########################################
NAME	=fdf

INCLUDES_PATH=	includes
CC=				gcc
CFLAGS=			-Wall -Wextra -Werror -g3 -fsanitize=address
CPPFLAGS=		-lglfw

LIBS_DIR=	./libs

all: $(NAME)

########################################
## SOURCES
########################################
SRC_FILES = fdf.c \
			vector.c \
			rotate.c \
			utils.c \
			parser.c

SRC_FILES := $(addprefix src/, $(SRC_FILES))
OBJ_FILES = $(SRC_FILES:.c=.o)

########################################
## RULES
########################################

all: $(NAME)

DO_LIBS:
	@echo DOING LIBS
	@make -C $(LIBS_DIR) all

$(NAME): $(OBJ_FILES) | DO_LIBS
	@echo LINKING
	$(CC) $^ -L$(LIBS_DIR) -lft -lmlx42 $(CFLAGS) $(CPPFLAGS) -o $@ -lm

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)
	@make -C $(LIBS_DIR) clean

fclean: clean
	@make -C $(LIBS_DIR) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re all
