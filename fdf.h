/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:57:51 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/13 17:06:06 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include "minilibx-linux/mlx.h"

# include <stdio.h>

# include <X11/keysym.h>
# include <X11/X.h>

# include <sys/types.h>
# include <sys/stat.h> 
# include <fcntl.h>

# include <stdlib.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_zoom
{
	int		zoom;
	int		height;
	int		width;
}			t_zoom;

typedef struct s_data
{
	float	xs;
	float	ys;
	int		max;
	int		z;
	int		z1;

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
	t_zoom	*fata;
}			t_data;

void	open_file(char *path, t_data *loco);
void	fill(int *num_line, int *color_line, char *line);
void	get_width(char *path, t_data *loco);
void	get_height(char *path, t_data *loco);
void	prepare_fill(t_data *loco, int fd);

int		counter(char *str, char c);
int		ft_atoi_base(const char *str, int base);

int		deal_key(int key, t_data *loco);
void	my_mlx_pixel_put(t_data *loco, int x, int y, int color);

void	draw(float xe, float ye, t_data *loco);
void	manage_points(t_data *loco);

//--------------close.c------------------
int		ft_close(t_data *loco);
int		close_me(t_data *loco);

//--------------map_utils.c--------------
void	free_matrix(void **ptr);
void	color(int *z, int *z1, t_data *loco);
void	shift(float *xe, float *ye, t_data *loco);
void	zoom(float *xe, float *ye, t_data *loco);
void	center(float *xe, t_data *loco);

//-------------map_init.c----------------
void	map_init(t_data *loco);

//-------------struct_initialize.c-------
void    initialize(t_data *loco);

#endif