/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:10:22 by ygao              #+#    #+#             */
/*   Updated: 2025/01/28 14:17:21 by ygao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	key_press(int keycode, t_cube *cube)
{
	if (keycode == W)
		cube->keys.w = true;
	else if (keycode == S)
		cube->keys.s = true;
	else if (keycode == A)
		cube->keys.a = true;
	else if (keycode == D)
		cube->keys.d = true;
	else if (keycode == LEFT)
		cube->keys.left = true;
	else if (keycode == RIGHT)
		cube->keys.right = true;
	else if (keycode == CLOSE_KEY || keycode == ESC)
	{
		free_all(cube);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

int	key_release(int keycode, t_cube *cube)
{
	if (keycode == W)
		cube->keys.w = false;
	else if (keycode == S)
		cube->keys.s = false;
	else if (keycode == A)
		cube->keys.a = false;
	else if (keycode == D)
		cube->keys.d = false;
	else if (keycode == LEFT)
		cube->keys.left = false;
	else if (keycode == RIGHT)
		cube->keys.right = false;
	return (0);
}

int	process_input(t_cube *cube)
{
	if (cube->keys.w)
		move_forward(cube);
	if (cube->keys.s)
		move_backward(cube);
	if (cube->keys.a)
		move_left(cube);
	if (cube->keys.d)
		move_right(cube);
	if (cube->keys.left)
		rotate_left(cube);
	if (cube->keys.right)
		rotate_right(cube);
	renew_display(cube);
	return (0);
}

void	move_left(t_cube *cube)
{
	int		x;
	int		y;
	double	angle;

	angle = cube->player->angle - M_PI / 2;
	if (angle < 0)
		angle += 2 * M_PI;
	else if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	x = (int)(cube->player->player_x + cos(angle) * cube->player->player_speed);
	y = (int)(cube->player->player_y + sin(angle) * cube->player->player_speed);
	if (x < 0 || y < 0 || x >= cube->map->map_width 
		|| y >= cube->map->digit_map_height)
		return ;
	if (cube->map->digit_map[y][x] != '1')
	{
		cube->player->player_x = cube->player->player_x
			+ cos(angle) * cube->player->player_speed;
		cube->player->player_y = cube->player->player_y
			+ sin(angle) * cube->player->player_speed;
	}
}

void	move_right(t_cube *cube)
{
	int		x;
	int		y;
	double	angle;

	angle = cube->player->angle + M_PI / 2;
	if (angle < 0)
		angle += 2 * M_PI;
	else if (angle > 2 * M_PI)
		angle -= 2 * M_PI;
	x = (int)(cube->player->player_x + cos(angle)
			* cube->player->player_speed);
	y = (int)(cube->player->player_y + sin(angle)
			* cube->player->player_speed);
	if (x < 0 || y < 0 || x >= cube->map->map_width
		|| y >= cube->map->digit_map_height)
		return ;
	if (cube->map->digit_map[y][x] != '1')
	{
		cube->player->player_x = cube->player->player_x
			+ cos(angle) * cube->player->player_speed;
		cube->player->player_y = cube->player->player_y
			+ sin(angle) * cube->player->player_speed;
	}
}
