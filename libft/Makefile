# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kacoulib <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/04 21:06:34 by kacoulib          #+#    #+#              #
#    Updated: 2016/12/01 13:28:31 by kacoulib         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =  libft.a
HEADERS	= libft.h
SOURCES = \
ft_atoi.c \
ft_bzero.c \
ft_freejoin.c \
ft_indexof.c \
ft_is_dir.c \
ft_is_file.c \
ft_isalnum.c \
ft_isalpha.c \
ft_isascii.c \
ft_isdigit.c \
ft_isprint.c \
ft_isspace.c \
ft_itoa.c \
ft_lstadd.c \
ft_lstdel.c \
ft_lstdelone.c \
ft_lstiter.c \
ft_lstmap.c \
ft_lstnew.c \
ft_lstpush.c \
ft_memalloc.c \
ft_memccpy.c \
ft_memchr.c \
ft_memcmp.c \
ft_memcpy.c \
ft_memdel.c \
ft_memmove.c \
ft_memset.c \
ft_pow.c \
ft_print.c \
ft_putchar.c \
ft_putchar_fd.c \
ft_putendl.c \
ft_putendl_fd.c \
ft_putfile.c \
ft_putnbr.c \
ft_putnbr_fd.c \
ft_putstr.c \
ft_putstr_fd.c \
ft_strcat.c \
ft_strchr.c \
ft_strclr.c \
ft_strcmp.c \
ft_strcpy.c \
ft_strdel.c \
ft_strdup.c \
ft_strequ.c \
ft_striter.c \
ft_striteri.c \
ft_strjoin.c \
ft_strlcat.c \
ft_strlen.c \
ft_strmap.c \
ft_strmapi.c \
ft_strncat.c \
ft_strncmp.c \
ft_strncpy.c \
ft_strnequ.c \
ft_strnew.c \
ft_strnstr.c \
ft_strpop.c \
ft_strrchr.c \
ft_strsplit.c \
ft_strstr.c \
ft_strsub.c \
ft_strtrim.c \
ft_tolower.c \
ft_toupper.c \
ft_ucfirst.c \
ft_last_indexof.c \
ft_strrev.c \
ft_preg_replace.c \
get_next_line.c \
free_arr.c \
ft_free.c \
del.c \
arr_contain.c \
arr_len.c


OBJ	= $(SOURCES:.c=.o)
FLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
		gcc $(FLAGS) -c $(HEADERS) $(SOURCES)  
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)
clean : 
	rm -rf *.o

fclean : clean
	rm -rf $(NAME)
re : fclean all
