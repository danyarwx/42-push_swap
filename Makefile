NAME		= push_swap

CC			= cc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f

PRINTF_DIR	= ft_printf
PRINTF		= $(PRINTF_DIR)/ft_printf.a

INCLUDES	= -I. -I$(PRINTF_DIR)/include

SRCS		= main.c				\
			  parsing.c				\
			  ft_split.c				\
			  errors.c				\
			  utils.c				\
			  tiny_sort.c			\
			  push_swap.c			\
			  push_swap_utils.c		\
			  push_swap_move.c		\
			  c_push.c				\
			  c_swap.c				\
			  c_rotate.c			\
			  c_revrotate.c

OBJS_DIR	= obj
OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all: $(NAME)

$(NAME): $(PRINTF) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(PRINTF) -o $(NAME)

$(PRINTF):
	$(MAKE) -C $(PRINTF_DIR)

$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

$(OBJS_DIR)/%.o: %.c push_swap.h | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(MAKE) -C $(PRINTF_DIR) clean
	$(RM) -r $(OBJS_DIR)

fclean: clean
	$(MAKE) -C $(PRINTF_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
