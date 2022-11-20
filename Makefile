# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25 16:57:06 by naal-jen          #+#    #+#              #
#    Updated: 2022/11/10 15:39:43 by naal-jen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
WFLAGS = -Wall -Werror -Wextra
AFLAGS = ar cr
MFLAGS = -Imlx -lXext -lX11
CFILES = main.c read_file.c get_orders.c
OFILES = main.o read_file.o get_orders.o
NAME = fdf.a

all: make $(NAME) compile

make:
	cd gnl; \
	$(MAKE); \
	cd ..; \
	cd libft; \
	$(MAKE); \
	cd ..;
	cd mlx_linux; \
	$(MAKE); \

$(NAME): $(OFILES)
	$(AFLAGS) $(NAME) $(OFILES)

$(OFILES): $(CFILES)
	$(CC) -c $(WFLAGS) $(CFILES)

compile:
	$(CC) $(OFILES) gnl/get_next_line.a libft/libft.a mlx_linux/libmlx.a $(MFLAGS)

clean:
	cd gnl; \
	$(MAKE) fclean; \
	cd ..; \
	cd libft; \
	$(MAKE) fclean; \
	cd ..; \
	cd mlx_linux; \
	$(MAKE) clean; \
	cd ..; \
	rm $(OFILES); \
	rm a.out

fclean: clean
	rm fdf.a

re: all make compile clean fclean
