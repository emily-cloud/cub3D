/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:16:34 by ygao              #+#    #+#             */
/*   Updated: 2025/01/28 14:17:07 by ygao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	move_forward(t_cube *cube)
{
	int	x;
	int	y;

	x = (int)(cube->player->player_x + cube->player->player_dir_x
			* cube->player->player_speed);
	y = (int)(cube->player->player_y + cube->player->player_dir_y
			* cube->player->player_speed);
	if (x < 0 || y < 0 || x >= cube->map->map_width 
		|| y >= cube->map->digit_map_height)
		return ;
	if (cube->map->digit_map[y][x] != '1')
	{
		cube->player->player_x = cube->player->player_x
			+ cube->player->player_dir_x * cube->player->player_speed;
		cube->player->player_y = cube->player->player_y
			+ cube->player->player_dir_y * cube->player->player_speed;
	}
}

void	move_backward(t_cube *cube)
{
	int	x;
	int	y;

	x = (int )(cube->player->player_x - cube->player->player_dir_x
			* cube->player->player_speed);
	y = (int)(cube->player->player_y - cube->player->player_dir_y
			* cube->player->player_speed);
	if (x < 0 || y < 0 || x >= cube->map->map_width 
		|| y >= cube->map->digit_map_height)
		return ;
	if (cube->map->digit_map[y][x] != '1')
	{
		cube->player->player_x = cube->player->player_x
			- cube->player->player_dir_x * cube->player->player_speed;
		cube->player->player_y = cube->player->player_y
			- cube->player->player_dir_y * cube->player->player_speed;
	}
}

void	rotate_left(t_cube *cube)
{
	cube->player->angle -= cube->player->player_rot_speed;
	cube->player->angle = normalize_angle(cube->player->angle);
	cube->player->player_dir_x = cos(cube->player->angle);
	cube->player->player_dir_y = sin(cube->player->angle);
	cube->player->planex = -1 * cube->player->player_dir_y
		* cube->player->plane_length;
	cube->player->planey = cube->player->player_dir_x
		* cube->player->plane_length;
}

void	rotate_right(t_cube *cube)
{
	cube->player->angle += cube->player->player_rot_speed;
	cube->player->angle = normalize_angle(cube->player->angle);
	cube->player->player_dir_x = cos(cube->player->angle);
	cube->player->player_dir_y = sin(cube->player->angle);
	cube->player->planex = -1 * cube->player->player_dir_y 
		* cube->player->plane_length;
	cube->player->planey = cube->player->player_dir_x 
		* cube->player->plane_length;
}

void	renew_display(t_cube *cube)
{
	mlx_destroy_image(cube->mlx, cube->three_d_image->img);
	mlx_destroy_image(cube->mlx, cube->map_image->img);
	free(cube->three_d_image);
	free(cube->map_image);
	init_map_image(cube);
	init_three_d_image(cube);
	draw_image(cube);
	mlx_clear_window(cube->mlx, cube->win);
	mlx_put_image_to_window(cube->mlx, cube->win,
		cube->three_d_image->img, 0, 0);
	mlx_put_image_to_window(cube->mlx, cube->win, cube->map_image->img, 0, 0);
}
