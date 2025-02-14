/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:21:18 by hai               #+#    #+#             */
/*   Updated: 2025/01/29 11:32:43 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_map_struct(t_cube *cube, char *line_copy)
{
	if (ft_strncmp("NO", line_copy, 2) == 0)
	{
		if (cube->map->north_flag == false)
			copy_map_line_dir(cube, line_copy, "NO");
		else
			print_error_close_window(cube, "more than one NO");
	}
	else if (ft_strncmp("SO", line_copy, 2) == 0)
	{
		if (cube->map->south_flag == false)
			copy_map_line_dir(cube, line_copy, "SO");
		else
			print_error_close_window(cube, "more than one SO");
	}
	else if (ft_strncmp("WE", line_copy, 2) == 0)
	{
		if (cube->map->west_flag == false)
			copy_map_line_dir(cube, line_copy, "WE");
		else
			print_error_close_window(cube, "more than one WE");
	}
	else if (ft_strncmp("EA", line_copy, 2) == 0
		|| *line_copy == 'F' || *line_copy == 'C')
		parse_map_struct_2(cube, line_copy);
}

void	parse_map_struct_2(t_cube *cube, char *line_copy)
{
	if (ft_strncmp("EA", line_copy, 2) == 0)
	{
		if (cube->map->east_flag == false)
			copy_map_line_dir(cube, line_copy, "EA");
		else
			print_error_close_window(cube, "more than one EA");
	}
	else if (*line_copy == 'F')
	{
		if (cube->map->floor_flag == false)
			copy_map_line_dir(cube, line_copy, "F");
		else
			print_error_close_window(cube, "more than one F");
	}
	else if (*line_copy == 'C')
	{
		if (cube->map->ceiling_flag == false)
			copy_map_line_dir(cube, line_copy, "C");
		else
			print_error_close_window(cube, "more than one C");
	}
}

void	search_player(t_cube *cube, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
			{
				cube->player->player_x = j + 0.5;
				cube->player->player_y = i + 0.5;
				check_direction(cube, map[i][j]);
				return ;
			}
			j++;
		}
		i++;
	}
	print_error_close_window(cube, "No player position");
}
