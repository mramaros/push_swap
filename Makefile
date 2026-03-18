NAME		=	push_swap
CFLAGS		=	-Wall -Wextra -Werror -g
OBJ_DIR		=	OBJ
LIBFT_A		=	ft_printf/libftprintf.a

SOURCE		=	bench_print.c \
				disorder_count.c \
				ft_atoi_long.c \
				ft_strcmp.c \
				main.c \
				medium_algo.c \
				medium_algo_utils.c \
				medium_algo_utils_utils.c \
				medium_index_assignment.c \
				parsing.c \
				sequences.c \
				sequences_ab.c \
				simple_algo.c \
				tab_assignation.c \
				utils.c \
				verify_another_num_strategy.c \
				verify_bench.c \
				utils_utils.c \
				complex_algo.c \
				adaptive_check.c

OBJECTS		=	$(addprefix $(OBJ_DIR)/, $(SOURCE:.c=.o))

all			:	$(NAME)
	@echo "Build Successful"

$(OBJ_DIR)	:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o	:	%.c | $(OBJ_DIR)
	cc $(CFLAGS) -c $< -o $@

$(NAME)		:	$(OBJECTS)
	cc $(CFLAGS) $(OBJECTS) $(LIBFT_A) -o $(NAME)

clean		:
	rm -rf $(OBJ_DIR)

fclean		:	clean
	rm -rf $(NAME)

re			:	fclean all

.PHONY		:	all clean fclean re
