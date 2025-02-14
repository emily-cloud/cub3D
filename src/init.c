/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 11:08:32 by hai               #+#    #+#             */
/*   Updated: 2025/01/29 10:02:44 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_cube_data(t_cube *cube)
{
	cube->mlx = mlx_init();
	cube->win = NULL;
	cube->three_d_image = NULL;
	cube->map_image = NULL;
	cube->oldtime = 0;
	cube->frametime = 0;
	cube->keys = (t_keys){0};
	cube->ray = NULL;
	cube->player = NULL;
	cube->map = NULL;
	cube->texture_img = NULL;
	cube->texture = NULL;
	init_map(cube);
	init_texture(cube);
	init_keys(cube);
	init_player(cube);
	init_ray(cube);
}

void	init_texture(t_cube *cube)
{
	cube->texture = malloc(sizeof(t_texture));
	if (!cube->texture)
		print_error_close_window(cube, "Memory allocation error");
	cube->texture->wall_height = 0;
	cube->texture->start = 0;
	cube->texture->end = 0;
	cube->texture->wall_x = 0;
	cube->texture->tex_x = 0;
	cube->texture->step = 0;
	cube->texture->tex_pos = 0;
	cube->texture->tex_y = 0;
	cube->texture->color = 0;
	cube->texture->tex_width = 64;
	cube->texture->tex_height = 64;
	cube->texture->texture_array = NULL;
}

void	init_map(t_cube *cube)
{
	cube->map = malloc(sizeof(t_map));
	if (!cube->map)
		print_error_close_window(cube, "Memory allocation error");
	cube->map->floor = NULL;
	cube->map->ceiling_flag = false;
	cube->map->floor_flag = false;
	cube->map->ceiling = NULL;
	cube->map->floor_color = 0;
	cube->map->ceiling_color = 0;
	cube->map->digit_map = NULL;
	cube->map->digit_map_copy = NULL;
	cube->map->full_map = NULL;
	cube->map->digit_map_height = 0;
	cube->map->map_lines = 0;
	cube->map->north = NULL;
	cube->map->south = NULL;
	cube->map->east = NULL;
	cube->map->west = NULL;
	cube->map->north_flag = false;
	cube->map->south_flag = false;
	cube->map->east_flag = false;
	cube->map->west_flag = false;
}

void	init_player(t_cube *cube)
{
	cube->player = malloc(sizeof(t_player));
	if (!cube->player)
		print_error_close_window(cube, "Memory allocation error");
	cube->player->player_direction = 0;
	cube->player->player_x = 0;
	cube->player->player_y = 0;
	cube->player->player_dir_x = 0;
	cube->player->player_dir_y = 0;
	cube->player->player_speed = 0.1;
	cube->player->player_rot_speed = 3 * (M_PI / 180);
	cube->player->planex = 0;
	cube->player->planey = 0;
	cube->player->plane_length = 0;
	cube->player->angle = 0;
	cube->player->perp_dist = 0;
}

void	init_ray(t_cube *cube)
{
	cube->ray = malloc(sizeof(t_ray));
	if (!cube->ray)
		print_error_close_window(cube, "Memory allocation error");
	cube->ray->ray_dir_x = 0;
	cube->ray->ray_dir_y = 0;
	cube->ray->side_dist_x = 0;
	cube->ray->side_dist_y = 0;
	cube->ray->delta_dist_x = 0;
	cube->ray->delta_dist_y = 0;
	cube->ray->step_x = 0;
	cube->ray->step_y = 0;
	cube->ray->map_x = 0;
	cube->ray->map_y = 0;
	cube->ray->hit = 0;
	cube->ray->side = 0;
	cube->ray->camera_x = 0;
}
