#########################################
## ARGUMENTS
#########################################
INCLUDES_PATH=../includes

NAME				= libfdf.a
CFLAGS				= -Wall -Wextra -Werror -g3 -fsanitize=address -I$(INCLUDES_PATH)
CC					= gcc

########################################
## SOURCES
########################################

SRC_FILES = test.c fdf.c

OBJ_FILES = $(SRC_FILES:.c=.o)

########################################
## RULES
########################################

all: $(NAME)

$(NAME) : $(OBJ_FILES)
	@echo DOING SRC.A
	@$(AR) rcs $@ $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME) $(LIBFT_NAME)

re: fclean all

.PHONY: clean fclean re all
