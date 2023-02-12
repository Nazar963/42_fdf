/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:29:31 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/12 18:49:53 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_me(t_data *loco)
{
	ft_close(loco);
	exit(0);
}

int	ft_close(t_data *loco)
{
	int	i;

	i = 0;
	while (i <= loco->height)
	{
		free(loco->grid[i]);
		i++;
	}
	free(loco->grid);
	i = 0;
	while (i <= loco->height)
	{
		free(loco->color_grid[i]);
		i++;
	}
	free(loco->color_grid);
	mlx_destroy_image(loco->mlx, loco->img);
	mlx_destroy_window(loco->mlx, loco->win);
	mlx_destroy_display(loco->mlx);
	free(loco->mlx);
	free(loco->fata);
	free(loco);
	exit(0);
}
