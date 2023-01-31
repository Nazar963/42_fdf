/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:30:04 by naal-jen          #+#    #+#             */
/*   Updated: 2023/01/31 15:51:45 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	deal_key(int key, t_data *loco)
{
	printf("%d\n", key);
	if (key == 119)
		loco->shift_y -= 40;
	if (key == 115)
		loco->shift_y += 40;
	if (key == 97)
		loco->shift_x -= 40;
	if (key == 100)
		loco->shift_x += 40;
	if (key == 65307)
	{
		mlx_clear_window(loco->mlx, loco->win);
		mlx_destroy_window(loco->mlx, loco->win);
	}
	mlx_clear_window(loco->mlx, loco->win);
	manage_points(loco);

	return (0);
}

int	main(int ac, char **av)
{
	t_data	*loco;
	t_color	*color;
	if (ac != 2)
		exit(EXIT_FAILURE);
	loco = (t_data *)malloc(sizeof(t_data));
	color = (t_color *)malloc(sizeof(t_color));
	open_file(av[1], loco);

	loco->mlx = mlx_init();
	loco->win = mlx_new_window(loco->mlx, 1000, 1000, "fdf");
	loco->zoom = 40;
	manage_points(loco);

	int i;
	int j;
	i = 0;
	while (i < loco->height)
	{
		j = 0;
		while (j < loco->width)
		{
			printf("%d  ", loco->grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	i = 0;
	while (i < loco->height)
	{
		j = 0;
		while (j < loco->width)
		{
			printf("%d  ", loco->color_grid[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	mlx_key_hook(loco->win, deal_key, loco);
	mlx_loop(loco->mlx);
}