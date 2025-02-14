/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:53:36 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 14:09:15 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_abs(double *x)
{
	if (*x < 0)
		*x *= -1;
}

void	draw_background(t_cube *cube)
{
	int	x;
	int	y;

	y = 0;
	while (y < cube->three_d_image->img_height / 2)
	{
		x = 0;
		while (x < cube->three_d_image->img_width)
		{
			fill_pixel(x, y, cube->map->ceiling_color, cube->three_d_image);
			x++;
		}
		y++;
	}
	while (y < cube->three_d_image->img_height)
	{
		x = 0;
		while (x < cube->three_d_image->img_width)
		{
			fill_pixel(x, y, cube->map->floor_color, cube->three_d_image);
			x++;
		}
		y++;
	}
}

void	fill_pixel(double x, double y, int color, t_img *img)
{
	int	int_x;
	int	int_y;
	int	pixel_offset;

	int_x = (int)x;
	int_y = (int)y;
	if (int_x < 0 || int_x >= img->img_width || int_y < 0
		|| int_y >= img->img_height)
		return ;
	pixel_offset = (int_y * img->line_length) + (int_x * (img->bpp / 8));
	((int *)img->img_addr)[pixel_offset / 4] = color;
}

void	draw_map(t_cube *cube)
{
	int	i;
	int	j;
	int	color;

	i = 0;
	while (cube->map->digit_map[i])
	{
		j = 0;
		while (cube->map->digit_map[i][j])
		{
			if (cube->map->digit_map[i][j] == '1')
				color = BLACK;
			else
				color = LIGHT_GREEN;
			draw_cell(cube, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_cell(t_cube *cube, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < CELL_SIZE)
	{
		j = 0;
		while (j < CELL_SIZE)
		{
			fill_pixel(x * CELL_SIZE + j, y * CELL_SIZE + i, color,
				cube->map_image);
			j++;
		}
		i++;
	}
}
