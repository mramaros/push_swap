# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/26 13:51:52 by ialrandr          #+#    #+#              #
#    Updated: 2026/03/11 21:24:36 by mramaros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SOURCE = ft_printf ft_printf_utils ft_printf_others\
			ft_hex ft_ltoa ft_printf_for_hundred

C_FLAGS = -Wall -Wextra -Werror -g

OBJ_FILE = OBJ

OBJECTS = $(addprefix $(OBJ_FILE)/, $(addsuffix .o, $(SOURCE)))

all : $(NAME)
	@echo "Build Successfull"

libFT :
	$(MAKE) -C libft all

$(OBJ_FILE) :
	@mkdir -p $(OBJ_FILE)

$(OBJ_FILE)/%.o : %.c | $(OBJ_FILE)
	cc $(C_FLAGS) -c $< -o $@

$(NAME) : libFT $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS) libft/OBJ/*.o

clean :
	$(MAKE) -C libft clean
	rm -rf $(OBJ_FILE)

fclean : clean
	$(MAKE) -C libft fclean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
