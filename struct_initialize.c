/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_initialize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:01:08 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/19 18:04:16 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	initialize(t_data *loco)
{
	loco->fata->zoom = 100;
	loco->fata->height = 0;
	loco->fata->width = 0;
	loco->xs = 0;
	loco->ys = 0;
	loco->max = 0;
	loco->z = 0;
	loco->z1 = 0;
	loco->width = 0;
	loco->height = 0;
	loco->zoom = 0;
	loco->color = 0;
	loco->shift_x = 0;
	loco->shift_y = 0;
	loco->addr = 0;
	loco->bpp = 0;
	loco->line_length = 0;
	loco->shift_check = 0;
	loco->endian = 0;
}
