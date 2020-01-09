# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: tmullan <tmullan@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/12/02 15:40:20 by tmullan        #+#    #+#                 #
#    Updated: 2020/01/08 21:12:43 by tmullan       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = gnlrun

OBJ = get_next_line.o get_next_line_utils.o testmain.o

FLAGS = -Wall -Wextra -Werror -g
# -D BUFFER_SIZE=1000

all: $(NAME)

$(NAME): $(OBJ)
		gcc -o $@ $^ $(FLAGS) 

%.o: %.c
		$(CC) -c -o $@ $<

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all
