/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:38:59 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/05 21:58:49 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	max_num(float a, float b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

static int mod(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

void	isometric_projection(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.9);
	*y = (*x + *y) * sin(0.9) - z;
}

void	draw(float xs, float ys, float xe, float ye, t_data *loco)
{
	float x_delta;
	float y_delta;
	int	max;
	int	z;
	int	z1;

	z = loco->grid[(int)ys][(int)xs];
	z1 = loco->grid[(int)ye][(int)xe];

	//----------color----------
	if (z || z1)
	{
		if (loco->color_grid[(int)ys][(int)xs] != 0)
			loco->color = loco->color_grid[(int)ys][(int)xs]; // 16711680 blue
		else
			loco->color = 0xffd700;
	}
	else
	{
		if (loco->color_grid[(int)ys][(int)xs] != 0)
			loco->color = loco->color_grid[(int)ys][(int)xs]; // 16711680 blue
		else
			loco->color = 0xffffff;
	}
	//----------zoom-----------
	xs *= loco->zoom;
	ys *= loco->zoom;
	xe *= loco->zoom;
	ye *= loco->zoom;
	//----------3D-------------
	isometric_projection(&xs, &ys, z);
	isometric_projection(&xe, &ye, z1);
	//----------shift----------
	xs += loco->shift_x;
	ys += loco->shift_y;
	xe += loco->shift_x;
	ye += loco->shift_y;
	//----------center---------
	xs += 950;
	ys += 0;
	xe += 950;
	ye += 0;

	
	x_delta = xe - xs;
	y_delta = ye - ys;

	max = max_num(mod(x_delta), mod(y_delta));
	// if (fabsf(x_delta) > fabs(y_delta))
	// 	max = fabsf(x_delta);
	// else
	// 	max = fabs(y_delta);
	x_delta /= max;
	y_delta /= max;
	while ((int)(xs - xe) || (int)(ys - ye))
	{
		// mlx_pixel_put(loco->mlx, loco->win, xs, ys, loco->color);
		my_mlx_pixel_put(loco, xs, ys, loco->color);
		xs += x_delta;
		ys += y_delta;
		if (xs < 0 || ys < 0)
		{
			loco->img = mlx_new_image(loco->mlx, WIDTH, HEIGHT);
			loco->addr = mlx_get_data_addr(loco->img ,&loco->bpp, &loco->line_length, &loco->endian);
			loco->zoom -= 1;
			// mlx_clear_window(loco->mlx, loco->win);
			manage_points(loco);
		}
		if (xs > WIDTH || ys > HEIGHT)
		{
			loco->img = mlx_new_image(loco->mlx, WIDTH, HEIGHT);
			loco->addr = mlx_get_data_addr(loco->img ,&loco->bpp, &loco->line_length, &loco->endian);
			loco->zoom -= 1;
			// mlx_clear_window(loco->mlx, loco->win);
			manage_points(loco);
		}

	}
}

void	manage_points(t_data *loco)
{
	int	x;
	int	y;

	y = 0;
	while (y < loco->height)
	{
		x = 0;
		while (x < loco->width)
		{
			if (x < loco->width - 1)
				draw(x, y, x + 1, y, loco);
			if (y < loco->height - 1)
				draw(x, y, x, y + 1, loco);
			x++;
		}
		y++;
	}
}


