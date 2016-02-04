# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nahmed-m <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/03 19:34:07 by nahmed-m          #+#    #+#              #
#*   Updated: 2016/02/04 19:59:41 by nahmed-m         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

SRC_NAME = main.c parsing.c

NAME = ft_ls

OBJ_NAME = $(SRC_NAME:.c=.o)

$(NAME) :
	@make fclean -C libft/ && make -C libft/
	@cp libft/libft.a .
	@gcc -Wall -Wextra -Werror -c $(SRC_NAME)
	@gcc -Wall -Wextra -Werror $(OBJ_NAME) -o $(NAME) -L. -lft
	@echo "\033[1;34m ----FT_LS----- :\033[m \033[1;32m DONE !\033[m"

all : $(NAME)

clean :
	@rm -rf $(OBJ_NAME)
	@rm -rf libft.a
	@make clean -C libft/
	@echo "\033[1;34m ----FT_LS----- :\033[m \033[1;32m DELETE OBJ FILES !\033[m"

fclean : clean
	@rm -rf $(NAME)
	@make fclean -C libft/
	@echo "\033[1;34m ----FT_LS----- :\033[m \033[1;32m DELETE FT_LS !\033[m"

re : fclean all

.PHONY : all re clean fclean
