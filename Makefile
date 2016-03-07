# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgeslin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/20 16:17:18 by jgeslin           #+#    #+#              #
#    Updated: 2016/03/07 11:02:50 by ssicard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIB = push.a

INC_DIR = includes

CC = gcc

CFLAGS = -I$(INC_DIR)

SOURCES = func.c\
		  func2.c\
		  func3.c\
		  func4.c\
		  func5.c\
		  ft_atoi_spec.c\
		  check.c\
		  check2.c\
		  bonus.c\
		  bonus2.c\
		  utils.c\
		  utils2.c

SRC = $(addprefix sources/,$(SOURCES))

OBJ = $(SRC:.c=.o)

all : $(NAME) $(LIB)

$(NAME) : $(LIB)
	@$(CC) -o $(NAME) main.c $(LIB) $(CFLAGS) libft/libft.a
	@echo "MiniOns Arrived!"
	@echo "A New Challenger!"

$(LIB) : $(OBJ)
	@ar -r $(LIB) $(OBJ)
	@ranlib $(LIB)
	@echo "Cpt. Push Lib. Arrived."

clean :
	@rm -rf $(OBJ)
	@echo "MiniOns Died!"

fclean : clean
	@rm -rf $(NAME) $(LIB)
	@echo "All's Destroyed! R.I.P :'("

re : fclean all
	@echo "And The Rain Against! ^^"

.PHONY: all clean fclean re
