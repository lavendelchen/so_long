# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shaas <shaas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 11:26:14 by shaas             #+#    #+#              #
#    Updated: 2021/11/29 22:25:55 by shaas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =

COMP = gcc -Wall -Wextra -Werror -c

C_FILES =

O_FILES = $(C_FILES:.c=.o)

BONUS_FILES = 

BONUS_O_FILES =  $(BONUS_FILES:.c=.o)

all: $(NAME) bonus

comp:
	$(COMP) $(C_FILES)

$(NAME): comp
	ar rc $(NAME) $(O_FILES)

clean:
	rm -f $(O_FILES) $(BONUS_O_FILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

bonuscomp:
	$(COMP) $(BONUS_FILES)

bonus: bonuscomp
	ar rc $(NAME) $(BONUS_O_FILES)
