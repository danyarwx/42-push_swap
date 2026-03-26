NAME = ft_printf.a

CC          := cc
CFLAGS      := -Wall -Wextra -Werror -I include
RM          := rm -f

SRC_DIR     := src
OBJ_DIR     := obj

SRCS := $(addprefix $(SRC_DIR)/, \
		ft_printf.c \
		ft_put_chars.c \
		ft_put_nbr.c \
		ft_put_unbr.c \
		ft_put_ptr.c \
		ft_put_hex.c)

OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJS)
	@$(RM) $(NAME)
	@ar rcs $(NAME) $(OBJS)
	@echo "built $(NAME)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c include/ft_printf.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) -r $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
