# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 21:00:17 by naal-jen          #+#    #+#              #
#    Updated: 2022/11/07 10:31:52 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
WFLAGS = -Wall -Werror -Wextra
CFILES = get_next_line.c get_next_line_utils.c
OFILES = $(CFILES:%.c=%.o)
AFLAGS = ar cr
NAME = get_next_line.a

all: $(NAME)

$(OFILES): $(CFILES)
	$(CC) -c $(WFLAGS) $(CFILES)

$(NAME): $(OFILES)
	$(AFLAGS) $(NAME) $(OFILES)

clean:
	rm *.o

fclean: clean
	rm get_next_line.a

re: all clean fclean

