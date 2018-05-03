#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oltkache <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/27 17:27:04 by oltkache          #+#    #+#              #
#    Updated: 2017/11/27 17:27:04 by oltkache         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fillit

SRC = ft_alg1.c ft_ch_val.c ft_check.c ft_comb.c main_goal.c read_ch1.c ft_alg2.c ft_alg3.c ft_alg4.c help.c

OBJ = ft_alg1.o ft_ch_val.o ft_check.o ft_comb.o main_goal.o read_ch1.o ft_alg2.o ft_alg3.o ft_alg4.o help.o

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

%.o : %.c
	gcc $(FLAGS) -c $<