# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialrandr <ialrandr@student.42antananari    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/09 10:10:42 by ialrandr          #+#    #+#              #
#    Updated: 2026/03/21 18:51:54 by mramaros         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SOURCE = ft_isalpha ft_isdigit ft_isalnum ft_isprint ft_isascii ft_strlen\
            ft_memset ft_bzero ft_memcpy ft_memmove ft_strlcpy\
            ft_strlcat ft_toupper ft_tolower ft_strchr\
            ft_strrchr ft_strncmp ft_memchr ft_memcmp ft_strnstr\
            ft_atoi ft_calloc ft_strdup ft_substr ft_strjoin\
            ft_strtrim ft_split ft_itoa ft_strmapi ft_striteri\
            ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd\
            ft_lstnew ft_lstadd_front ft_lstsize ft_lstlast ft_lstadd_back\
            ft_lstdelone ft_lstclear ft_lstiter ft_lstmap

C_FLAGS = -Wall -Wextra -Werror

OBJ_FILE = OBJ

OBJECTS = $(addprefix $(OBJ_FILE)/, $(addsuffix .o, $(SOURCE)))

all : $(NAME)
	@echo "Build Successfull"

$(OBJ_FILE) :
	@mkdir -p $(OBJ_FILE)

$(OBJ_FILE)/%.o : %.c | $(OBJ_FILE)
	cc $(C_FLAGS) -c $< -o $@

$(NAME) : $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

clean :
	rm -rf $(OBJ_FILE)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
