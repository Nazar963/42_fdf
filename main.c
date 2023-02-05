/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:30:04 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/05 09:48:50 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_me(void *param)
{
	(void)param;
	exit(0);
}

int	ft_close(t_data *loco)
{
	int	i;

	i = 0;
	if (loco->grid)
	{
		while (i <= loco->height)
		{
			free(loco->grid[i]);
			i++;
		}
		free(loco->grid);
	}
	i = 0;
	if (loco->color_grid)
	{
		while (i <= loco->height)
		{
			free(loco->color_grid[i]);
			i++;
		}
		free(loco->color_grid);
	}
	mlx_destroy_window(loco->mlx, loco->win);
	mlx_destroy_display(loco->mlx);
	free(loco->mlx);
	free(loco->win);
	free(loco);
	exit(0);
}

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
		mlx_destroy_display(loco->mlx);
		ft_close(loco);
		exit(0);
	}
	loco->img = mlx_new_image(loco->mlx, WIDTH, HEIGHT);
	loco->addr = mlx_get_data_addr(loco->img ,&loco->bpp, &loco->line_length, &loco->endian);
	mlx_put_image_to_window(loco->mlx, loco->win, loco->img, 0, 0);
	manage_points(loco);
	return (0);
}

void	my_mlx_pixel_put(t_data *loco, int x, int y, int color)
{
	char	*dst;

	dst = loco->addr + (y * loco->line_length + x * (loco->bpp / 8));
	*(unsigned int*)dst = color;
}

int	main(int ac, char **av)
{
	t_data	*loco;

	if (ac != 2)
		exit(EXIT_FAILURE);
	loco = (t_data *)malloc(sizeof(t_data));
	if (!loco)
		exit(EXIT_FAILURE);
	loco->shift_check = 0;
	open_file(av[1], loco);
	loco->mlx = mlx_init();
	loco->win = mlx_new_window(loco->mlx, WIDTH, HEIGHT, "/|/|<<");
	loco->img = mlx_new_image(loco->mlx, WIDTH, HEIGHT);
	loco->addr = mlx_get_data_addr(loco->img ,&loco->bpp, &loco->line_length, &loco->endian);
	loco->zoom = 40;
	manage_points(loco);
	mlx_put_image_to_window(loco->mlx, loco->win, loco->img, 0, 0);
	mlx_hook(loco->win, 17, 0L, close_me, loco);
	mlx_hook(loco->win, 2, 1L<<0, deal_key, loco);
	// mlx_key_hook(loco->win, deal_key, loco);
	mlx_loop(loco->mlx);
}
