/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 09:08:17 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 14:16:14 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_all(t_cube *cube)
{
	if (cube->three_d_image)
	{
		free_image_struct(cube->three_d_image, cube->mlx);
		cube->three_d_image = NULL;
	}
	if (cube->map_image)
	{
		free_image_struct(cube->map_image, cube->mlx);
		cube->map_image = NULL;
	}
	if (cube->texture_img)
	{
		free_image_struct(cube->texture_img, cube->mlx);
		cube->texture_img = NULL;
	}
	if (cube->texture)
	{
		free_texture_struct(cube->texture);
		cube->texture = NULL;
	}
	if (cube->ray)
		free(cube->ray);
	free_all_helper(cube);
}

void	free_all_helper(t_cube *cube)
{
	if (cube->player)
	{
		free(cube->player);
		cube->player = NULL;
	}
	if (cube->map != NULL)
	{
		free_map_struct(cube->map);
		cube->map = NULL;
	}
	if (cube->mlx && cube->win)
	{
		mlx_destroy_window(cube->mlx, cube->win);
		cube->win = NULL;
	}
	if (cube->mlx)
	{
		mlx_destroy_display(cube->mlx);
		free(cube->mlx);
		cube->mlx = NULL;
	}
	free(cube);
}

void	free_map_struct(t_map *map)
{
	if (map->floor)
		free(map->floor);
	if (map->ceiling)
		free(map->ceiling);
	if (map->digit_map)
		free(map->digit_map);
	if (map->digit_map_copy)
		free(map->digit_map_copy);
	if (map->full_map)
		free_map(map->full_map);
	if (map->north)
		free(map->north);
	if (map->south)
		free(map->south);
	if (map->east)
		free(map->east);
	if (map->west)
		free(map->west);
	free(map);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
	map = NULL;
}

void	free_texture_struct(t_texture *texture)
{
	if (texture->texture_array)
	{
		free_texture_array(texture->texture_array);
		texture->texture_array = NULL;
	}
	free(texture);
}
