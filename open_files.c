/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:19:12 by naal-jen          #+#    #+#             */
/*   Updated: 2023/02/09 21:57:23 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int     get_height(char *path)
{
	char    *line;
	int     fd;
	int     height;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		return (0);
		exit(EXIT_FAILURE);
	}
	height = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int		get_width(char *path)
{
	int		width;
	int		fd;
	char	*line;
	// int		holder;

	// holder = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		return(0);
		exit(EXIT_FAILURE);
	}
	while ((line = get_next_line(fd)) != NULL)
	{
		if (line[ft_strlen(line)] == ' ')
		{
			width = counter(line, ' ');
			width--;
		}
		else
			width = counter(line, ' ');
		// if (width > holder)
		// 	holder = width;
		free(line);
	}
	close(fd);
	// return (holder);
	return (width);
}

void	fill(int *num_line, int *color_line, char *line)
{
	char	**res;
	char	**helper_color;
	int		i;
	int		j;

	res = ft_split(line, ' ');
	i = 0;
	j = 0;
	while (res[i])
	{
		if (ft_strchr(res[i], ',') != NULL)
		{
			helper_color = ft_split(res[i], ',');
			num_line[i] = ft_atoi(helper_color[0]);
			color_line[i] = ft_atoi_base(helper_color[1], 16);
			while (helper_color[j])
			{
				free(helper_color[j]);
				j++;
			}
			free(helper_color);
			free(res[i]);
		}
		else
		{
			num_line[i] = ft_atoi(res[i]);
			color_line[i] = 0;
			free(res[i]);
		}
		i++;
	}
	free(res);
}

void    open_file(char *path, t_data *loco)
{
	int		fd;
	char	*line;
	int		i;

	loco->height = get_height(path);
	loco->width = get_width(path);
	loco->grid = (int **)malloc((loco->height + 1) * sizeof(int*));
	if (!loco->grid)
		return (0);
	loco->color_grid = (int **)malloc((loco->height + 1) * sizeof(int*));
	if (!loco->color_grid)
		return (0);
	i = 0;
	while (i <= loco->height)
	{
		loco->grid[i++] = (int *)malloc(sizeof(int) * (loco->width + 1));
		if (!loco->grid[i - 1])
			return (0);
	}
	i = 0;
	while (i <= loco->height)
	{
		loco->color_grid[i++] = (int *)malloc(sizeof(int) * (loco->width + 1));
		if (!loco->color_grid[i - 1])
			return (0);
	}

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (0);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		fill(loco->grid[i], loco->color_grid[i], line);
		free(line);
		i++;
	}
	close(fd);
	loco->grid[i] = NULL;
	loco->color_grid[i] = NULL;
}