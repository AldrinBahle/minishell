# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agama <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/18 18:36:22 by agama             #+#    #+#              #
#    Updated: 2018/09/18 07:13:01 by agama            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= minishell

SRCS_PATH 	= srcs/
OBJ_PATH  	= obj/
LIBFT_PATH 	= libft/

FLAGS 		= -Wall -Werror -Wextra
INC 		= -I ./includes/ -I ./$(LIBFT_PATH)includes/

SRCS_NAME = $(shell ls $(SRCS_PATH) | grep -E ".+\.c")
SRCS = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS_NAME:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@gcc $(FLAGS) $(OBJ) $(INC) -L $(LIBFT_PATH) -lft -o $(NAME)
	@echo "\033[32mBinary \033[1;32m$(NAME)\033[1;0m\033[32m created.\033[0m"

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	@gcc -c $(FLAGS) $(INC) $< -o $@

clean:
	@make -C $(LIBFT_PATH)/ clean
	@/bin/rm -rf $(OBJ_PATH)
	@echo "\033[31mminishell object files \033[1;31m$(OBJS_LIST)\033[1;0m\033[31m removed.\033[0m"

fclean: clean
	@make -C $(LIBFT_PATH)/ fclean
	@/bin/rm -rf $(NAME)
	@echo "\033[31mBinary \033[1;31m$(NAME)\033[1;0m\033[31m removed.\033[0m"

re: fclean all

.PHONY: all, clean, fclean, re
