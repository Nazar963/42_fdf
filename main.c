/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:30:04 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/10 21:53:00 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	close_me(t_data *loco)
{
	ft_close(loco);
	exit(0);
	return (0);
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
	mlx_destroy_image(loco->mlx, loco->img);
	if (loco->mlx && loco->win)
		mlx_destroy_window(loco->mlx, loco->win);
	mlx_destroy_display(loco->mlx);
	free(loco->mlx);
	free(loco->win);
	free(loco->fata);
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

	if (x >= WIDTH || x <= 0 || y >= HEIGHT || y <= 0)
		return ;
	dst = loco->addr + (y * loco->line_length + x * (loco->bpp / 8));
	*(unsigned int*)dst = color;
}

static void	zoom_check(t_data *loco)
{
	int x;
	int y;
	// int	z;


	x = loco->width;
	y = 0;
	//----------zoom-----------
	x *= loco->fata->zoom;

	x = (x - y) * cos(0.9);
	//----------center---------
	x += 950;
	while (x > 1920)
	{
		x = loco->fata->width;
		//----------zoom-----------
		x *= loco->fata->zoom;
		x = (x - y) * cos(0.9);
		//----------center---------
		x += 950;
		loco->fata->zoom--;
	}

	//---------- for the y --------
	x = loco->fata->width;
	y = loco->fata->height;
	// z = loco->grid[(int)y][(int)x];
	//----------zoom-----------
	x *= loco->fata->zoom;
	y *= loco->fata->zoom;

	x = (x - y) * cos(0.9);
	y = (x + y) * sin(0.9);
	//----------center---------
	x += 950;
	while (x > WIDTH || y > HEIGHT)
	{
		x = loco->fata->width;
		y = loco->fata->height;
		//----------zoom-----------
		x *= loco->fata->zoom;
		y *= loco->fata->zoom;
		
		x = (x - y) * cos(0.9);
		y = (x + y) * sin(0.9);
		//----------center---------
		x += 950;
		loco->fata->zoom--;
	}
}

int	main(int ac, char **av)
{
	t_data	*loco;

	if (ac != 2)
		exit(EXIT_FAILURE);
	loco = (t_data *)malloc(sizeof(t_data));
	if (!loco)
		exit(EXIT_FAILURE);
	loco->fata = (t_zoom *)malloc(sizeof(t_zoom));
	if (!loco->fata)
		return (0);
	open_file(av[1], loco);
	loco->mlx = mlx_init();
	loco->win = mlx_new_window(loco->mlx, WIDTH, HEIGHT, "/|/|<< FDF");
	loco->img = mlx_new_image(loco->mlx, WIDTH, HEIGHT);
	loco->addr = mlx_get_data_addr(loco->img ,&loco->bpp, &loco->line_length, &loco->endian);
	loco->fata->zoom = 100;
	loco->fata->height = loco->height;
	loco->fata->width = loco->width;
	zoom_check(loco);
	loco->zoom = loco->fata->zoom;
	// loco->zoom = 10;
	manage_points(loco);
	mlx_put_image_to_window(loco->mlx, loco->win, loco->img, 0, 0);
	mlx_hook(loco->win, 17, 0L, close_me, (void *)loco);
	mlx_hook(loco->win, 2, 1L << 0, deal_key, loco);
	// mlx_key_hook(loco->win, deal_key, loco);
	mlx_loop(loco->mlx);
	return (0);
}
