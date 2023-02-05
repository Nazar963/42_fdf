# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/23 20:01:55 by naal-jen          #+#    #+#              #
#    Updated: 2023/02/05 17:40:55 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
WFLAGS = -Wall -Werror -Wextra
AFLAGS = ar cr
MFLAGS = -lXext -lX11 -lm -lz 
CFILES = main.c open_files.c utils.c draw_line.c
OFILES = main.o open_files.o utils.o draw_line.o
NAME = fdf.a

all: make $(NAME) compile

make:
	cd gnl; \
	$(MAKE); \
	cd ..; \
	cd libft; \
	$(MAKE); \
	cd ..;
	cd minilibx-linux; \
	$(MAKE); \

$(NAME): $(OFILES)
	$(AFLAGS) $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	$(CC) -g -c $(WFLAGS) $(CFILES)

compile:
	$(CC) $(OFILES) gnl/get_next_line.a libft/libft.a minilibx-linux/libmlx.a $(MFLAGS)

clean:
	cd gnl; \
	$(MAKE) fclean; \
	cd ..; \
	cd libft; \
	$(MAKE) fclean; \
	cd ..; \
	cd minilibx-linux; \
	$(MAKE) clean; \
	cd ..; \
	rm $(OFILES); \
	rm a.out

fclean: clean
	rm fdf.a

re: all make compile clean fclean