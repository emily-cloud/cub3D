/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 12:09:41 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 13:54:35 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_image(t_cube *cube)
{
	draw_background(cube);
	draw_map(cube);
	dda_cast_ray(cube);
}

void	dda_cast_ray(t_cube *cube)
{
	int	x;

	x = 0;
	while (x < cube->three_d_image->img_width)
	{
		cube->ray->camera_x = 2 * x / (double)cube->three_d_image->img_width
			- 1;
		cube->ray->ray_dir_x = cube->player->player_dir_x + cube->player->planex
			* cube->ray->camera_x;
		cube->ray->ray_dir_y = cube->player->player_dir_y + cube->player->planey
			* cube->ray->camera_x;
		find_wall(cube, x);
		x++;
	}
}

void	find_wall(t_cube *cube, int x)
{
	cube->ray->map_x = (int)cube->player->player_x;
	cube->ray->map_y = (int)cube->player->player_y;
	cube->ray->hit = 0;
	calculate_delta_dist(cube);
	side_dist_x_y(cube);
	check_wall_hit(cube);
	calculate_player_perp_dist(cube);
	draw_ray_on_map(cube);
	put_texture_to_wall(cube, x);
}

void	check_wall_hit(t_cube *cube)
{
	while (cube->ray->hit == 0)
	{
		if (cube->ray->side_dist_x < cube->ray->side_dist_y)
		{
			cube->ray->side_dist_x += cube->ray->delta_dist_x;
			cube->ray->map_x += cube->ray->step_x;
			cube->player->side = 0;
		}
		else
		{
			cube->ray->side_dist_y += cube->ray->delta_dist_y;
			cube->ray->map_y += cube->ray->step_y;
			cube->player->side = 1;
		}
		if (cube->map->digit_map[cube->ray->map_y][cube->ray->map_x] == '1')
			cube->ray->hit = 1;
	}
}

void	calculate_player_perp_dist(t_cube *cube)
{
	if (cube->player->side == 0)
	{
		cube->player->perp_dist = (cube->ray->side_dist_x
				- cube->ray->delta_dist_x);
		ft_abs(&cube->player->perp_dist);
	}
	else
	{
		cube->player->perp_dist = (cube->ray->side_dist_y
				- cube->ray->delta_dist_y);
		ft_abs(&cube->player->perp_dist);
	}
}
