/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:57:51 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/04 21:06:27 by naal-jen         ###   ########.fr       */
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

#define WIDTH 1000
#define HEIGHT 1000

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
	void	*img;
	void	*addr;

	int		bpp;
	int		line_length;
	int		shift_check;
	int		endian;
}			t_data;

void    open_file(char *path, t_data *loco);
void	fill(int *num_line, int *color_line, char *line);
int		get_width(char *path);
int     get_height(char *path);

int	counter(char *str, char c);
int	ft_atoi_base(const char *str, int base);

int	ft_close(t_data *loco);
int	deal_key(int key, t_data *loco);
void	my_mlx_pixel_put(t_data *loco, int x, int y, int color);
int	main(int ac, char **av);

void	draw(float xs, float ys, float xe, float ye, t_data *loco);
void	manage_points(t_data *loco);


#endif