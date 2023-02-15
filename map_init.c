/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 09:39:18 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/13 17:11:20 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_init(t_data *loco)
{
	loco->img = NULL;
	loco->mlx = mlx_init();
	loco->win = mlx_new_window(loco->mlx, WIDTH, HEIGHT, "/|/|<< FDF");
	loco->img = mlx_new_image(loco->mlx, WIDTH, HEIGHT);
	loco->addr = mlx_get_data_addr(loco->img, &loco->bpp, &loco->line_length,
			&loco->endian);
}