/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:57:51 by naal-jen          #+#    #+#             */
/*   Updated: 2023/01/31 13:06:44 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include "minilibx-linux/mlx.h"

#include <stdio.h>

#include <X11/keysym.h>
#include <X11/X.h>

#include <sys/types.h>
#include <sys/stat.h> 
#include <fcntl.h>

#include <stdlib.h>
#include <math.h>

typedef struct s_data
{
	int		width;
	int		height;
	int		**grid;
	int		**color_grid;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;

	void	*mlx;
	void	*win;
}			t_data;

typedef struct s_color
{
	unsigned int	red_i;
	unsigned int	green_i;
	unsigned int	blue_i;
	unsigned int	color_i;

	unsigned char	red_start;
	unsigned char	green_start;
	unsigned char	blue_start;

	unsigned char	red_end;
	unsigned char	green_end;
	unsigned char	blue_end;
}			t_color;

void    open_file(char *path, t_data *loco);
void	fill(int *num_line, int *color_line, char *line);
int		get_width(char *path);
int     get_height(char *path);

int	counter(char *str, char c);
int	ft_atoi_base(const char *str, int base);

int	deal_key(int key, t_data *loco);
int	main(int ac, char **av);

void	draw(float xs, float ys, float xe, float ye, t_data *loco, t_color color);
void	manage_points(t_data *loco);

int	color_manage(int end_color, t_color color);

#endif