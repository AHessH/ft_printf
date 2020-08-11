# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: froxanne <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/01 11:02:01 by froxanne          #+#    #+#              #
#    Updated: 2020/07/11 14:57:37 by froxanne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_LFT =		libft/ft_atoi.c \
				libft/ft_bzero.c \
				libft/ft_calloc.c \
				libft/ft_isalnum.c \
				libft/ft_isalpha.c \
				libft/ft_isascii.c \
				libft/ft_isdigit.c \
				libft/ft_isprint.c \
				libft/ft_itoa.c \
				libft/ft_memccpy.c \
				libft/ft_memchr.c \
				libft/ft_memcmp.c \
				libft/ft_memcpy.c \
				libft/ft_memmove.c \
				libft/ft_memset.c \
				libft/ft_putchar_fd.c \
				libft/ft_putendl_fd.c \
				libft/ft_putnbr_fd.c \
				libft/ft_putstr_fd.c \
				libft/ft_split.c \
				libft/ft_strchr.c \
				libft/ft_strdup.c \
				libft/ft_strjoin.c \
				libft/ft_strlcat.c \
				libft/ft_strlcpy.c \
				libft/ft_strlen.c \
				libft/ft_strmapi.c \
				libft/ft_strncmp.c \
				libft/ft_strnstr.c \
				libft/ft_strrchr.c \
				libft/ft_strtrim.c \
				libft/ft_substr.c \
				libft/ft_tolower.c \
				libft/ft_toupper.c \
				libft/ft_isconver.c \
				libft/ft_isflags.c \
				libft/ft_ismodif.c \
				libft/ft_putchar.c \
				libft/ft_print_space.c \
				libft/ft_putchars.c \
				libft/ft_ullitoa_base.c \
				libft/ft_putstr.c \
				libft/ft_pow.c \
				libft/ft_max.c \
				libft/ft_abs.c \
				srcs/parse.c \
				srcs/qual.c \
				srcs/main_parse.c \
				srcs/ft_printf.c \
				srcs/print_chars.c \
				srcs/print_func.c \
				srcs/print_str.c \
				srcs/print_num.c \
				srcs/print_u_num.c \
				srcs/print_x_num.c \
				srcs/print_p.c \
				srcs/take_len.c \
				srcs/print_perc.c

OBJ_LFT = $(SRC_LFT:.c=.o)

OBJ_PR = $(SRC_PR:.c=.o)

NAME = libftprintf.a

AR = ar rcs $(NAME)

CL = clang

FLAGS = -Wall -Werror -Wextra 

all: $(NAME)

%.o: %.c
	$(CL) $(FLAGS) -c $< -o $@

$(NAME): $(OBJ_LFT)
	$(AR) $?

clean:
	rm -rf */*.o
	rm -rf *.o

fclean: clean
	rm libftprintf.a
	
re: fclean all

bonus: all
