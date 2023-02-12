/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 20:52:39 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/12 20:53:03 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color(int *z, int *z1, t_data *loco)
{
	*z *= loco->zoom / 3.5;
	*z1 *= loco->zoom / 3.5;
	if (*z || *z1)
	{
		if (loco->color_grid[(int)loco->ys][(int)loco->xs] != 0)
			loco->color = loco->color_grid[(int)loco->ys][(int)loco->xs];
		else
			loco->color = 0xffd700;
	}
	else
	{
		if (loco->color_grid[(int)loco->ys][(int)loco->xs] != 0)
			loco->color = loco->color_grid[(int)loco->ys][(int)loco->xs];
		else
			loco->color = 0xffffff;
	}
	loco->xs *= loco->zoom;
	loco->ys *= loco->zoom;
}

void	shift(float *xe, float *ye, t_data *loco)
{
	loco->xs += loco->shift_x;
	loco->ys += loco->shift_y;
	*xe += loco->shift_x;
	*ye += loco->shift_y;
}

void	zoom(float *xe, float *ye, t_data *loco)
{
	*xe *= loco->zoom;
	*ye *= loco->zoom;
}

void	center(float *xe, t_data *loco)
{
	loco->xs += 950;
	*xe += 950;
}