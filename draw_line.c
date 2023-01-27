/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:38:59 by naal-jen          #+#    #+#             */
/*   Updated: 2023/01/27 19:26:21 by naal-jen         ###   ########.fr       */
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
	*x = (*x - *y) * cos(0.523599);
	*y = (*x + *y) * sin(0.523599) - z;
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


	//----------zoom-----------
	xs *= loco->zoom;
	ys *= loco->zoom;
	xe *= loco->zoom;
	ye *= loco->zoom;
	//----------color----------
	if (z || z1)
		loco->color = 0xe80c0c;
	else
		loco->color = 0xffffff;
	//----------3D-------------
	isometric_projection(&xs, &ys, z);
	isometric_projection(&xe, &ye, z1);
	//----------shift----------
	xs += loco->shift_x;
	ys += loco->shift_y;
	xe += loco->shift_x;
	ye += loco->shift_y;
	
	x_delta = xe - xs;
	y_delta = ye - ys;

	max = max_num(mod(x_delta), mod(y_delta));
	x_delta /= max;
	y_delta /= max;
	while ((int)(xs - xe) || (int)(ys - ye))
	{
		mlx_pixel_put(loco->mlx, loco->win, xs, ys, loco->color);
		xs += x_delta;
		ys += y_delta;
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


// void	draw(int xs, int ys, int xe, int ye, t_data *loco)
// {
// 	int x_delta;
// 	int y_delta;
// 	int	pk;
// 	int x;
// 	int y;

// 	pk = 0;
// 	x_delta = xe - xs;
// 	y_delta = ye - ys;

// 	x = xs;
// 	y = ys;
// 	pk = (2 * y_delta) - x_delta;

// 	while (x < xe)
// 	{
// 		if (pk >= 0)
// 		{
// 			pk += (2 * y_delta) - (2 * x_delta);
// 			mlx_pixel_put(loco->mlx, loco->win, x, y, 0xffffff);
// 			y++;
// 		}
// 		else
// 		{
// 			pk += (2 * y_delta);
// 			mlx_pixel_put(loco->mlx, loco->win, x, y, 0xffffff);
// 			x++;
// 		}

// 	}
	
// 	// while ((int)(xs - xe) || (int)(ys - ye))
// 	// {
// 	// 	while (pk > 0)
// 	// 	{
// 	// 		pk += (2 * y_delta) - x_delta;
// 	// 		mlx_pixel_put(loco->mlx, loco->win, xs, ys, 0xffffff);
// 	// 		xs++;
// 	// 		ys++;
// 	// 	}
// 	// 	while (pk < 0)
// 	// 	{
// 	// 		pk += (2 * y_delta);
// 	// 		mlx_pixel_put(loco->mlx, loco->win, xs, ys, 0xffffff);
// 	// 		xs++;
// 	// 	}
// 	// }
// }