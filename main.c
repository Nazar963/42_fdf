/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:40:14 by naal-jen          #+#    #+#             */
/*   Updated: 2022/11/12 11:30:48 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		i;
	int		j;
	int		count;
	int		width;
	int		height;
	int		x;
	int		y;
	char	*line;
	int		fd;
	int		z;

	x = 0;
	y = 0;
	z = 0;
	if (argc != 2)
		exit(1);
	read_process(argv[1], &width, &height);
	width *= 50;
	height *= 50;
	printf("%d\n%d\n", width, height);

	i = 50;
	j = 50;
	count = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "fdf");
	img.img = mlx_new_image(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	while (i <= width)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		if (count == 50)
		{
			count = 0;
			while (j <= height)
			{
				my_mlx_pixel_put(&img, i, j, 0x00FF0000);
				j++;
			}
			j = 50;
		}
		count++;
		i++;
	}
	j = 50;
	while (j <= height)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		if (count == 50)
		{
			count = 0;
			while (i >= 50)
			{
				my_mlx_pixel_put(&img, i, j, 0x00FF0000);
				i--;
			}
			i = width;
		}
		count++;
		j++;
	}
	i = width;
	while (i >= 50)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		i--;
	}
	while (j >= 50)
	{
		my_mlx_pixel_put(&img, i, j, 0x00FF0000);
		j--;
	}
	fd = open(argv[1], O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		while (line[z] != '\0')
		{
			printf("hello\n");
			file_orders(line, &z, &x, &y);
			count = x - 50;
			while (count <= x)
			{
				my_mlx_pixel_put(&img, count, y, 0x000000FF);
				count++;
			}
			count = x + 50;
			while (count >= x)
			{
				my_mlx_pixel_put(&img, count, y, 0x000000FF);
				count--;
			}
			count = y - 50;
			while (count <= y)
			{
				my_mlx_pixel_put(&img, x, count, 0x000000FF);
				count++;
			}
			count = y + 50;
			while (count >= y)
			{
				my_mlx_pixel_put(&img, x, count, 0x000000FF);
				count--;
			}
			z++;
		}
		free(line);
	}
	close(fd);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}