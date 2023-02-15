/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:19:12 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/13 09:44:14 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	get_height(char *path, t_data *loco)
{
	char	*line;
	int		fd;
	int		height;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_close(loco);
	height = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	loco->height = height;
}

void	get_width(char *path, t_data *loco)
{
	int		width;
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_close(loco);
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (line[ft_strlen(line)] == ' ')
		{
			width = counter(line, ' ');
			width--;
		}
		else
			width = counter(line, ' ');
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	loco->width = width;
}

void	fill(int *num_line, int *color_line, char *line)
{
	char	**res;
	char	**helper_color;
	int		i;

	res = ft_split(line, ' ');
	i = 0;
	while (res[i])
	{
		if (ft_strchr(res[i], ',') != NULL)
		{
			helper_color = ft_split(res[i], ',');
			num_line[i] = ft_atoi(helper_color[0]);
			color_line[i] = ft_atoi_base(helper_color[1], 16);
			free_matrix((void **)helper_color);
		}
		else
		{
			num_line[i] = ft_atoi(res[i]);
			color_line[i] = ft_atoi("0");
		}
		i++;
	}
	free_matrix((void **)res);
}

void	prepare_fill(t_data *loco, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		fill(loco->grid[i], loco->color_grid[i], line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

void	open_file(char *path, t_data *loco)
{
	int		fd;
	int		i;

	i = -1;
	get_height(path, loco);
	get_width(path, loco);
	loco->grid = (int **)malloc((loco->height + 1) * sizeof(int *));
	loco->color_grid = (int **)malloc((loco->height + 1) * sizeof(int *));
	if ((!loco->color_grid) || (!loco->color_grid))
		ft_close(loco);
	while (++i < loco->height)
	{
		loco->grid[i] = (int *)malloc(sizeof(int) * (loco->width + 1));
		loco->color_grid[i] = (int *)malloc(sizeof(int) * (loco->width + 1));
		if ((!loco->color_grid[i]) || (!loco->grid[i]))
			ft_close(loco);
	}
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_close(loco);
	prepare_fill(loco, fd);
	close(fd);
	loco->grid[i] = NULL;
	loco->color_grid[i] = NULL;
}
