/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 12:08:14 by naal-jen          #+#    #+#             */
/*   Updated: 2022/11/09 11:41:02 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	get_width(char *file)
{
	int		fd;
	char	*line;
	int		count;
	int		i;

	i = -1;
	count = 0;
	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	while (line[++i])
	{
		if (line[i] != ' ')
			count++;
	}
	free(line);
	close(fd);
	return (count - 1);
}

static int	get_height(char *file)
{
	int		fd;
	char	*line;
	int		count;

	count = 0;
	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		count++;
		free(line);
	}
	close(fd);
	return ((count / 2) + 1);
}


void	read_process(char *file, int *width, int *height)
{
	*width = get_width(file);
	*height = get_height(file);

	int		fd;
	char	*line;

	fd = open(file, O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}