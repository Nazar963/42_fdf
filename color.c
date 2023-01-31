/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naal-jen <naal-jen@student.42firenze.it    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:44:02 by naal-jen          #+#    #+#             */
/*   Updated: 2023/01/31 13:01:13 by naal-jen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	color_manage(int end_color, t_color color) //16777215
{
	int	base_color;

	unsigned int	quotient;
	unsigned int	hex_color_start;
	unsigned int	i;
	unsigned int	temp;
	unsigned int	hex_color_end;

	base_color = 16777215;
	quotient = base_color;
	hex_color_start = 0;
	i = 1;

	while (quotient != 0)
	{
		temp = quotient % 16;
		if (temp < 10)
			temp += 48;
		else
			temp = 55;
		hex_color_start += temp * i;
		i *= 16;
		quotient /= 16;
	}

	quotient = end_color;
	hex_color_end = 0;
	i = 1;
	while (quotient != 0)
	{
		temp = quotient % 16;
		if (temp < 10)
			temp += 48;
		else
			temp = 55;
		hex_color_end += temp * i;
		i *= 16;
		quotient /= 16;
	}

	color.red_start = (hex_color_start & 0xFF0000) >> 16;
	color.green_start = (hex_color_start & 0x00FF00) >> 8;
	color.blue_start = (hex_color_start & 0x0000FF);

	color.red_end = (hex_color_end & 0xFF0000) >> 16;
	color.green_end = (hex_color_end & 0x00FF00) >> 8;
	color.blue_end = (hex_color_end & 0x0000FF);


	// unsigned int color_i = (red_i << 16) | (green_i << 8) | blue_i;
}