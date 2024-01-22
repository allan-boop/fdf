#########################################
## ARGUMENTS
#########################################

INCLUDES_PATH = ../../includes
NAME		= libft.a
CFLAGS		= -Wextra -Wall -Werror -I$(INCLUDES_PATH) -g3
CC			= gcc

########################################
## SOURCES
########################################

SRC_FILES =	\
	ft_putnbr_fd.c \
	ft_putendl_fd.c \
	ft_putstr_fd.c \
	ft_putchar_fd.c \
	ft_striteri.c \
	ft_strmapi.c \
	ft_itoa.c \
	ft_split.c \
	ft_strtrim.c \
	ft_strjoin.c \
	ft_substr.c \
	ft_strdup.c \
	ft_calloc.c \
	ft_atoi.c \
	ft_strnstr.c \
	ft_memcmp.c \
	ft_memchr.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_strlen.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_printf.c \
	ft_putstr.c \
	arg_c.c \
	arg_s.c \
	arg_d.c \
	arg_x.c \
	arg_u.c \
	arg_p.c \
	arg_percent.c \
	ft_lstmap_bonus.c \
	ft_lstiter_bonus.c \
	ft_lstclear_bonus.c \
	ft_lstdelone_bonus.c \
	ft_lstadd_back_bonus.c \
	ft_lstlast_bonus.c \
	ft_lstsize_bonus.c \
	ft_lstadd_front_bonus.c \
	ft_lstnew_bonus.c \
	ft_atol.c \
	get_next_line_bonus.c

OBJ_FILES =	$(SRC_FILES:.c=.o)

########################################
## RULES
########################################

all: $(NAME)

$(NAME): $(OBJ_FILES)
	@$(AR) rcs $@ $(OBJ_FILES)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ_FILES)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
