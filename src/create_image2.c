/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:52:44 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 14:07:00 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	side_dist_x_y(t_cube *cube)
{
	if (cube->ray->ray_dir_x < 0)
	{
		cube->ray->step_x = -1;
		cube->ray->side_dist_x = (cube->player->player_x - cube->ray->map_x)
			* cube->ray->delta_dist_x;
	}
	else
	{
		cube->ray->step_x = 1;
		cube->ray->side_dist_x = (cube->ray->map_x + 1.0
				- cube->player->player_x) * cube->ray->delta_dist_x;
	}
	if (cube->ray->ray_dir_y < 0)
	{
		cube->ray->step_y = -1;
		cube->ray->side_dist_y = (cube->player->player_y - cube->ray->map_y)
			* cube->ray->delta_dist_y;
	}
	else
	{
		cube->ray->step_y = 1;
		cube->ray->side_dist_y = (cube->ray->map_y + 1.0
				- cube->player->player_y) * cube->ray->delta_dist_y;
	}
}

void	put_texture_to_wall(t_cube *cube, int x)
{
	int	tex_num;

	cube->texture->wall_height = (cube->three_d_image->img_height
			/ cube->player->perp_dist);
	cube->texture->start = -cube->texture->wall_height / 2
		+ cube->three_d_image->img_height / 2;
	if (cube->texture->start < 0)
		cube->texture->start = 0;
	cube->texture->end = cube->texture->wall_height / 2
		+ cube->three_d_image->img_height / 2;
	if (cube->texture->end >= cube->three_d_image->img_height)
		cube->texture->end = cube->three_d_image->img_height - 1;
	tex_num = cube->map->digit_map[cube->ray->map_y][cube->ray->map_x] - '1';
	if (cube->player->side == 0)
		cube->texture->wall_x = cube->player->player_y + cube->player->perp_dist
			* cube->ray->ray_dir_y;
	else
		cube->texture->wall_x = cube->player->player_x + cube->player->perp_dist
			* cube->ray->ray_dir_x;
	cube->texture->wall_x -= floor(cube->texture->wall_x);
	cube->texture->tex_x = (int)(cube->texture->wall_x
			* (double)cube->texture->tex_width);
	detect_side(cube, &tex_num);
	fill_pixel_to_wall(cube, x, tex_num);
}

void	fill_pixel_to_wall(t_cube *cube, int x, int tex_num)
{
	cube->texture->step = 1.0 * cube->texture->tex_height
		/ cube->texture->wall_height;
	cube->texture->tex_pos = (cube->texture->start
			- cube->three_d_image->img_height / 2 + cube->texture->wall_height
			/ 2) * cube->texture->step;
	while (cube->texture->start < cube->texture->end)
	{
		cube->texture->tex_y = (int)cube->texture->tex_pos
			& (cube->texture->tex_height - 1);
		cube->texture->tex_pos += cube->texture->step;
		cube->texture->color = cube->texture->texture_array[tex_num]
		[cube->texture->tex_height
			* cube->texture->tex_y + cube->texture->tex_x];
		if (cube->player->side == 1)
			cube->texture->color = (cube->texture->color >> 1) & 8355711;
		fill_pixel(x, cube->texture->start, cube->texture->color,
			cube->three_d_image);
		cube->texture->start++;
	}
}

void	detect_side(t_cube *cube, int *tex_num)
{
	if (cube->player->side == 0 && cube->ray->ray_dir_x > 0)
	{
		cube->texture->tex_x = cube->texture->tex_width - cube->texture->tex_x
			- 1;
		*tex_num = 2;
	}
	if (cube->player->side == 0 && cube->ray->ray_dir_x < 0)
	{
		cube->texture->tex_x = cube->texture->tex_width - cube->texture->tex_x
			- 1;
		*tex_num = 3;
	}
	if (cube->player->side == 1 && cube->ray->ray_dir_y > 0)
	{
		cube->texture->tex_x = cube->texture->tex_width - cube->texture->tex_x
			- 1;
		*tex_num = 1;
	}
	if (cube->player->side == 1 && cube->ray->ray_dir_y < 0)
	{
		cube->texture->tex_x = cube->texture->tex_width - cube->texture->tex_x
			- 1;
		*tex_num = 0;
	}
}

void	draw_ray_on_map(t_cube *cube)
{
	int		n;
	double	step_x;
	double	step_y;
	double	x;
	double	y;

	n = 300;
	x = cube->player->player_x * CELL_SIZE;
	y = cube->player->player_y * CELL_SIZE;
	step_x = cube->ray->ray_dir_x * cube->player->perp_dist / n;
	step_y = cube->ray->ray_dir_y * cube->player->perp_dist / n;
	while (n > 0)
	{
		fill_pixel(x, y, BLUE, cube->map_image);
		x += step_x * CELL_SIZE;
		y += step_y * CELL_SIZE;
		n--;
	}
}
