# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mramaros <mramaros@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/19 11:23:01 by mramaros          #+#    #+#              #
#    Updated: 2026/03/23 17:45:13 by mramaros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		  =	push_swap
NAME_BONUS    =	checker
CFLAGS		  =	-Wall -Wextra -Werror -g
OBJ_DIR		  =	OBJ

SOURCE		  =	bench_print.c \
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
				utils.c \
				verify_another_num_strategy.c \
				verify_bench.c \
				utils_utils.c \
				complex_algo.c \
				complex_utils.c\
				adaptive_check.c \
				simple_algo_optimised.c \
				simple_algo_optimised_utils.c \
				parsing_utils.c

SOURCE_BONUS  = checker_bonus.c\
				get_next_line_utils_bonus.c\
				get_next_line_bonus.c\
				main_bonus.c\
				ft_strcmp.c \
				parsing.c \
				sequences.c \
				sequences_ab.c \
				disorder_count.c \
				utils.c\
				verify_another_num_strategy.c\
				ft_atoi_long.c

OBJECTS		  =	$(addprefix $(OBJ_DIR)/, $(SOURCE:.c=.o))

OBJECTS_BONUS =	$(addprefix $(OBJ_DIR)/, $(SOURCE_BONUS:.c=.o))

all			   : $(NAME)
	@echo "Build Successful"

bonus		   : $(NAME_BONUS)
	@echo "Bonus Build Successfully"

printf		   :
	$(MAKE) -C ft_printf all

$(OBJ_DIR)	   :
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : %.c | $(OBJ_DIR)
	cc $(CFLAGS) -c $< -o $@

$(NAME)		   : $(OBJECTS) printf
	cc $(CFLAGS) $(OBJECTS) ft_printf/libftprintf.a -o $(NAME)

$(NAME_BONUS)  : $(OBJECTS_BONUS) printf
	cc $(CFLAGS) $(OBJECTS_BONUS) ft_printf/libftprintf.a -o $(NAME_BONUS)

clean		   :
	$(MAKE) -C ft_printf clean
	rm -rf $(OBJ_DIR)

fclean		   : clean
	$(MAKE) -C ft_printf fclean
	rm -rf $(NAME)
	rm -rf $(NAME_BONUS)

re			   : fclean all

.PHONY		   : all clean fclean re
