/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 19:19:12 by naal-jen          #+#    #+#             */
/*   Updated: 2023/01/26 18:15:24 by naal-jen         ###   ########.fr       */
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
		exit(EXIT_FAILURE);
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
	int		holder;

	holder = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	while ((line = get_next_line(fd)) != NULL)
	{
		width = counter(line, ' ');
		if (width > holder)
			holder = width;
		free(line);
	}
	close(fd);
	return (holder);
}

void	fill(int *num_line, char *line)
{
	char	**res;
	int		i;

	res = ft_split(line, ' ');
	i = 0;
	while (res[i])
	{
		num_line[i] = ft_atoi(res[i]);
		free(res[i]);
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
	i = 0;
	while (i <= loco->height)
		loco->grid[i++] = (int *)malloc(sizeof(int) * (loco->width + 1));
	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		fill(loco->grid[i], line);
		free(line);
		i++;
	}
	close(fd);
	loco->grid[i] = NULL;
}