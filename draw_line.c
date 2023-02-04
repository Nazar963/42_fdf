/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:38:59 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/04 18:15:54 by naal-jen         ###   ########.fr       */
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

// static void	shift_image(t_data *loco, float *x, float *y)
// {
// 	int		offset_x;
// 	int		offset_y;

// 	offset_x = 0;
// 	offset_y = 0;
// 	if (*x < 0)
// 	{
// 		offset_x = (int)fabs(*x);
// 	}
// 	if (*y < 0)
// 	{
// 		offset_y = (int)fabs(*y);
// 	}
// 	loco->addr += offset_y * loco->line_length + offset_x * (loco->bpp / 8);
// 	*x = offset_x;
// 	*y = offset_y;
// }

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
	// if (loco->shifter_check == 0)
	// {
	xs += 500;
	ys += 500;
	xe += 500;
	ye += 500;
	// }

	
	x_delta = xe - xs;
	y_delta = ye - ys;

	max = max_num(mod(x_delta), mod(y_delta));
	x_delta /= max;
	y_delta /= max;
	while ((int)(xs - xe) || (int)(ys - ye))
	{
		// mlx_pixel_put(loco->mlx, loco->win, xs, ys, loco->color);
		my_mlx_pixel_put(loco, xs, ys, loco->color);
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


