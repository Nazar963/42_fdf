/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 15:19:38 by naal-jen          #+#    #+#             */
/*   Updated: 2022/11/10 15:39:04 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "mlx_linux/mlx.h"
#include "gnl/get_next_line.h"
#include "libft/libft.h"

#include <stdio.h>

#include <X11/keysym.h>
#include <X11/X.h>

#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 1000

void	read_process(char *file, int *width, int *height);
void	file_orders(char *line, int *i, int *x, int *y);

#endif