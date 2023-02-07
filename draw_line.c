/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 21:38:59 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/07 13:20:20 by naal-jen         ###   ########.fr       */
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

// static void	rotate_x(int *y, int *z, double alpha)
// {
// 	int	previous_y;

// 	previous_y = *y;
// 	*y = previous_y * cos(alpha) + *z * sin(alpha);
// 	*z = -previous_y * sin(alpha) + *z * cos(alpha);
// }

// static void	rotate_y(int *x, int *z, double beta)
// {
// 	int	previous_x;

// 	previous_x = *x;
// 	*x = previous_x * cos(beta) + *z * sin(beta);
// 	*z = -previous_x * sin(beta) + *z * cos(beta);
// }

// void	iso(int *x, int *y, int z)
// {
// 	int	previous_x;
// 	int	previous_y;

// 	previous_x = *x;
// 	previous_y = *y;
// 	*x = (previous_x - previous_y) * cos(0.83599);
// 	*y = -z + (previous_x + previous_y) * sin(0.599);
// }

// t_point	project(t_point p, t_fdf *fdf)
// {
// 	p.x *= fdf->camera->zoom;
// 	p.y *= fdf->camera->zoom;
// 	p.z *= fdf->camera->zoom / fdf->camera->z_divisor;
// 	p.x -= (fdf->map->width * fdf->camera->zoom) / 2;
// 	p.y -= (fdf->map->height * fdf->camera->zoom) / 2;
// 	rotate_x(&p.y, &p.z, fdf->camera->alpha);
// 	rotate_y(&p.x, &p.z, fdf->camera->beta);
// 	if (fdf->camera->projection == threeD)
// 		iso(&p.x, &p.y, p.z);
// 	p.x += WIDTH / 2 + fdf->camera->x_offset;
// 	p.y += HEIGHT / 2 + fdf->camera->y_offset;
// 	return (p);
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
	// xs += 950;
	// ys += 10;
	// xe += 950;
	// ye += 10;

	
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
			break ;
		if (xs > WIDTH || ys > HEIGHT)
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
				draw(x, y, x + 1, y, loco);
			if (y < loco->height - 1)
				draw(x, y, x, y + 1, loco);
			x++;
		}
		y++;
	}
}


