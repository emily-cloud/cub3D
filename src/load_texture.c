/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:54:07 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 14:08:19 by ygao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	load_texture(t_cube *cube)
{
	int	i;

	i = 0;
	malloc_texture_array(cube);
	while (i < 4)
	{
		cube->texture_img = malloc(sizeof(t_img));
		if (!cube->texture_img)
			print_error_close_window(cube, "Memory allocation error");
		if (i == 0)
			load_xpm_to_array(cube, cube->map->north, 0);
		else if (i == 1)
			load_xpm_to_array(cube, cube->map->south, 1);
		else if (i == 2)
			load_xpm_to_array(cube, cube->map->east, 2);
		else if (i == 3)
			load_xpm_to_array(cube, cube->map->west, 3);
		free(cube->texture_img);
		cube->texture_img = NULL;
		i++;
	}
	free(cube->texture_img);
}

void	malloc_texture_array(t_cube *cube)
{
	int	i;

	i = 0;
	cube->texture->texture_array = malloc(sizeof(uint32_t *) * 5);
	if (!cube->texture->texture_array)
		print_error_close_window(cube, "Memory allocation error");
	while (i < 4)
	{
		cube->texture->texture_array[i] = NULL;
		i++;
	}
	cube->texture->texture_array[i] = NULL;
}

void	load_xpm_to_array(t_cube *cube, char *s, int i)
{
	cube->texture_img->img = mlx_xpm_file_to_image(cube->mlx, s,
			&cube->texture->tex_width, &cube->texture->tex_height);
	if (!cube->texture_img->img)
		print_error_close_window(cube, "Failed to load texture");
	cube->texture_img->img_addr = mlx_get_data_addr(cube->texture_img->img,
			&cube->texture_img->bpp,
			&cube->texture_img->line_length,
			&cube->texture_img->endian);
	cube->texture->texture_array[i] = malloc(cube->texture->tex_width
			* cube->texture->tex_height * sizeof(uint32_t));
	if (cube->texture->texture_array[i] == NULL)
		print_error_close_window(cube, "Memory allocation error");
	convert_color_to_buffer(cube, i);
	mlx_destroy_image(cube->mlx, cube->texture_img->img);
	cube->texture_img->img = NULL;
}

void	convert_color_to_buffer(t_cube *cube, int i)
{
	int			pixel_index;
	uint32_t	color;
	int			x;
	int			y;

	y = 0;
	pixel_index = 0;
	color = 0;
	while (y < cube->texture->tex_height)
	{
		x = 0;
		while (x < cube->texture->tex_width)
		{
			pixel_index = y * cube->texture_img->line_length
				+ x * (cube->texture_img->bpp / 8);
			color = *(uint32_t *)(cube->texture_img->img_addr + pixel_index);
			cube->texture->texture_array[i][y * (64) + x] = color;
			x++;
		}
		y++;
	}
}
