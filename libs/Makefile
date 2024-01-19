#########################################
## ARGUMENTS
#########################################

NAME=libs
LIBS=libft.a libmlx42.a

#				MLX42

MLX42_LIB=libmlx42.a
MLX42_PATH=./MLX42

#				LIBFT

LIBFT=libft.a
LIBFT_PATH=./libft

########################################
## RULES
########################################

all : $(NAME)

$(MLX42_LIB):
	@echo DOING MLX42.A
	@cmake $(MLX42_PATH) -B $(MLX42_PATH)/build
	@cmake --build $(MLX42_PATH)/build -j4
	@mv $(MLX42_PATH)/build/libmlx42.a .

$(LIBFT):
	@echo DOING LIBFT.A
	@make -C $(LIBFT_PATH)
	@mv $(LIBFT_PATH)/$(LIBFT) .

$(NAME): $(MLX42_LIB) $(LIBFT)

clean :
	@make -C $(LIBFT_PATH) clean
	@rm -rf MLX42/build

fclean : clean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(LIBS)

re : fclean all

.PHONY: all clean fclean re
