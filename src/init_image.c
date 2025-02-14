/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 11:47:31 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 14:19:20 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_three_d_image(t_cube *cube)
{
	cube->three_d_image = malloc(sizeof(t_img));
	if (!cube->three_d_image)
		print_error_close_window(cube, "Memory allocation error");
	cube->three_d_image->endian = 0;
	cube->three_d_image->bpp = 32;
	cube->three_d_image->line_length = WIN_WIDTH * 4;
	cube->three_d_image->img = mlx_new_image(cube->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!cube->three_d_image->img)
		print_error_close_window(cube, "Failed to create new image");
	cube->three_d_image->img_addr = mlx_get_data_addr(cube->three_d_image->img,
			&cube->three_d_image->bpp, &cube->three_d_image->line_length,
			&cube->three_d_image->endian);
	if (!cube->three_d_image->img_addr)
		print_error_close_window(cube, "Failed to get image address");
	cube->three_d_image->img_width = WIN_WIDTH;
	cube->three_d_image->img_height = WIN_HEIGHT;
}

void	init_map_image(t_cube *cube)
{
	cube->map_image = malloc(sizeof(t_img));
	if (!cube->map_image)
		print_error_close_window(cube, "Memory allocation error");
	cube->map_image->endian = 0;
	cube->map_image->bpp = 32;
	cube->map_image->line_length = cube->map->map_width * CELL_SIZE * 4;
	cube->map_image->img = mlx_new_image(cube->mlx, cube->map->map_width
			* CELL_SIZE, cube->map->digit_map_height * CELL_SIZE);
	if (!cube->map_image->img)
		print_error_close_window(cube, "Failed to create new image");
	cube->map_image->img_addr = mlx_get_data_addr(cube->map_image->img,
			&cube->map_image->bpp, &cube->map_image->line_length,
			&cube->map_image->endian);
	if (!cube->map_image->img_addr)
		print_error_close_window(cube, "Failed to get image address");
	cube->map_image->img_width = cube->map->map_width * CELL_SIZE;
	cube->map_image->img_height = cube->map->digit_map_height * CELL_SIZE;
}
