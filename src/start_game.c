/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:09:42 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 13:57:32 by ygao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	start_game(t_cube *cube)
{
	cube->win = mlx_new_window(cube->mlx, WIN_WIDTH, WIN_HEIGHT, "my_cub3D");
	if (!cube->win)
		print_error_close_window(cube, "Error to create window");
	create_display(cube);
	mlx_hook(cube->win, KEY_PRESS, 1L << 0, &key_press, cube);
	mlx_hook(cube->win, KEY_RELEASE, 1L << 1, &key_release, cube);
	mlx_hook(cube->win, CLOSE_KEY, 0, &close_window, cube);
	mlx_loop_hook(cube->mlx, &process_input, cube);
	mlx_loop(cube->mlx);
}

void	create_display(t_cube *cube)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	cube->oldtime = time.tv_sec * 1000 + time.tv_usec / 1000;
	init_three_d_image(cube);
	init_map_image(cube);
	draw_image(cube);
	mlx_put_image_to_window(cube->mlx, cube->win, 
		cube->three_d_image->img, 0, 0);
	mlx_put_image_to_window(cube->mlx, cube->win, 
		cube->map_image->img, 0, 0);
	calculate_fps(cube);
}

void	calculate_fps(t_cube *cube)
{
	struct timeval	time;
	long			newtime;

	gettimeofday(&time, NULL);
	newtime = time.tv_sec * 1000.0 + time.tv_usec / 1000.0;
	cube->frametime = (newtime - cube->oldtime) / 1000.0;
	cube->oldtime = newtime;
	cube->player->player_speed = 1.0 * cube->frametime;
	cube->player->player_rot_speed = 1.0 * cube->frametime;
}
