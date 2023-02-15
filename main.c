/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 11:30:04 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/13 17:10:56 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_mouse_press(int key_code, int x, int y, t_data *loco)
{
	(void) x;
	(void) y;
	if (key_code == 4)
		loco->zoom += 2;
	else if (key_code == 5)
		loco->zoom -= 2;
	if (loco->img)
		mlx_destroy_image(loco->mlx, loco->img);
	loco->img = mlx_new_image(loco->mlx, WIDTH, HEIGHT);
	loco->addr = mlx_get_data_addr(loco->img, &loco->bpp, &loco->line_length,
			&loco->endian);
	manage_points(loco);
	mlx_put_image_to_window(loco->mlx, loco->win, loco->img, 0, 0);
	return (0);
}

int	deal_key(int key, t_data *loco)
{
	if (key == 119)
		loco->shift_y -= 40;
	if (key == 115)
		loco->shift_y += 40;
	if (key == 97)
		loco->shift_x -= 40;
	if (key == 100)
		loco->shift_x += 40;
	if (key == 4 || key == 61)
		loco->zoom += 2;
	if (key == 5 || key == 45)
		loco->zoom -= 2;
	if (key == 65307)
	{
		ft_close(loco);
		exit(0);
	}
	if (loco->img)
		mlx_destroy_image(loco->mlx, loco->img);
	loco->img = mlx_new_image(loco->mlx, WIDTH, HEIGHT);
	loco->addr = mlx_get_data_addr(loco->img, &loco->bpp, &loco->line_length,
			&loco->endian);
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
	*(unsigned int *)dst = color;
}

static void	zoom_check(t_data *loco)
{
	int	x;
	int	y;

	loco->fata->height = loco->height;
	loco->fata->width = loco->width;
	x = loco->fata->width;
	y = loco->fata->height;
	x *= loco->fata->zoom;
	y *= loco->fata->zoom;
	x = (x - y) * cos(0.9);
	y = (x + y) * sin(0.9);
	x += 950;
	while (x > WIDTH || y > HEIGHT)
	{
		x = loco->fata->width;
		y = loco->fata->height;
		x *= loco->fata->zoom;
		y *= loco->fata->zoom;
		x = (x - y) * cos(0.9);
		y = (x + y) * sin(0.9);
		x += 950;
		loco->fata->zoom--;
	}
	loco->zoom = loco->fata->zoom;
}

int	main(int ac, char **av)
{
	t_data	*loco;

	if (ac != 2)
		exit(EXIT_FAILURE);
	if (ft_strnstr(av[1], ".fdf", ft_strlen(av[1])) == 0)
		exit(EXIT_FAILURE);
	loco = (t_data *)malloc(sizeof(t_data));
	if (!loco)
		exit(EXIT_FAILURE);
	loco->fata = (t_zoom *)malloc(sizeof(t_zoom));
	if (!loco->fata)
		exit(EXIT_FAILURE);
	initialize(loco);
	open_file(av[1], loco);
	if (loco->height == 0 || loco->width == 0)
		ft_close(loco);
	map_init(loco);
	zoom_check(loco);
	manage_points(loco);
	mlx_put_image_to_window(loco->mlx, loco->win, loco->img, 0, 0);
	mlx_hook(loco->win, 17, 0L, close_me, (void *)loco);
	mlx_hook(loco->win, 2, 1L << 0, deal_key, (void *)loco);
	mlx_mouse_hook(loco->win, ft_mouse_press, (void *)loco);
	mlx_loop(loco->mlx);
}
