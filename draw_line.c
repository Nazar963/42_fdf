/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:38:59 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/12 20:52:22 by naal-jen         ###   ########.fr       */
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

static int	mod(float a)
{
	if (a < 0)
		return (-a);
	else
		return (a);
}

static void	isometric_projection(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.9);
	*y = (*x + *y) * sin(0.9) - z;
}

void	draw(float xe, float ye, t_data *loco)
{
	float	x_delta;
	float	y_delta;

	loco->z = loco->grid[(int)loco->ys][(int)loco->xs];
	loco->z1 = loco->grid[(int)ye][(int)xe];
	color(&loco->z, &loco->z1, loco);
	zoom(&xe, &ye, loco);
	isometric_projection(&loco->xs, &loco->ys, loco->z);
	isometric_projection(&xe, &ye, loco->z1);
	shift(&xe, &ye, loco);
	center(&xe, loco);
	x_delta = xe - loco->xs;
	y_delta = ye - loco->ys;
	loco->max = max_num(mod(x_delta), mod(y_delta));
	x_delta /= loco->max;
	y_delta /= loco->max;
	while ((int)(loco->xs - xe) || (int)(loco->ys - ye))
	{
		my_mlx_pixel_put(loco, loco->xs, loco->ys, loco->color);
		loco->xs += x_delta;
		loco->ys += y_delta;
		if (loco->xs < 0 || loco->ys < 0
			|| loco->xs > WIDTH || loco->ys > HEIGHT)
			break ;
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
			{
				loco->xs = x;
				loco->ys = y;
				draw(loco->xs + 1, loco->ys, loco);
			}
			if (y < loco->height - 1)
			{
				loco->xs = x;
				loco->ys = y;
				draw(loco->xs, loco->ys + 1, loco);
			}
			x++;
		}
		y++;
	}
}
