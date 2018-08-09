# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kacoulib <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/10/01 21:18:08 by kacoulib          #+#    #+#              #
#    Updated: 2017/10/01 21:18:10 by kacoulib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	fdf
SRCS_NAME	=	main.c\
				ft_parsing.c\
				ft_get_data.c\
				ft_calculs.c
SRCS_PATH	=	srcs/
SRCS			=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ_NAME	=	$(SRCS_NAME:.c=.o)
OBJ_PATH	=	obj/
OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))
FLAGS			=	-Wall -Wextra -Werror
INC				=	-I./includes/ -I./libft/ -I./minilibx
LIB				=	-L minilibx -lmlx -framework OpenGL -framework AppKit \
					-L libft -lft\


.PHONY: all, clean, fclean, re

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx/
	gcc $(FLAGS) -o $(NAME) $(OBJ) $(INC) $(LIB)

all: $(NAME)

$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p obj
	gcc -c $(FLAGS) $< -o $@ $(INC)

clean:
	make -C minilibx/ clean
	make -C libft/ fclean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
