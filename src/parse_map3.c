/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:00:43 by ygao              #+#    #+#             */
/*   Updated: 2025/01/29 11:32:51 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	digit_map_parse(t_cube *cube, int start_line)
{
	int		i;
	int		lines;

	lines = cube->map->map_lines - start_line;
	cube->map->digit_map_height = lines;
	i = 0;
	cube->map->digit_map = malloc((lines + 1) * sizeof(char *));
	cube->map->digit_map_copy = malloc((lines + 1) * sizeof(char *));
	if (!cube->map->digit_map || !cube->map->digit_map_copy)
		print_error_close_window(cube, "Memory allocation error");
	while (i < lines)
	{
		cube->map->digit_map[i] = cube->map->full_map[start_line];
		cube->map->digit_map_copy[i] = cube->map->full_map[start_line];
		start_line++;
		i++;
	}
	cube->map->digit_map[i] = NULL;
	cube->map->digit_map_copy[i] = NULL;
	discard_empty_line(cube);
	search_player(cube, cube->map->digit_map);
}

void	discard_empty_line(t_cube *cube)
{
	int	lines;

	lines = 0;
	while (cube->map->digit_map[lines])
	{
		lines++;
	}
	while (cube->map->digit_map[lines - 1][0] == '\0')
	{
		cube->map->digit_map[lines - 1] = NULL;
		cube->map->digit_map_copy[lines - 1] = NULL;
		lines--;
	}
}

void	check_direction(t_cube *cube, char c)
{
	if (c == 'N')
	{
		cube->player->player_direction = 'N';
		cube->player->angle = 270 * (M_PI / 180.0);
	}
	else if (c == 'S')
	{
		cube->player->player_direction = 'S';
		cube->player->angle = 90 * (M_PI / 180.0);
	}
	else if (c == 'W')
	{
		cube->player->player_direction = 'W';
		cube->player->angle = 180 * (M_PI / 180.0);
	}
	else if (c == 'E')
	{
		cube->player->player_direction = 'E';
		cube->player->angle = 0 * (M_PI / 180.0);
	}
	check_direction_cal(cube);
}

void	check_direction_cal(t_cube *cube)
{
	cube->player->player_dir_x = cos(cube->player->angle);
	cube->player->player_dir_y = sin(cube->player->angle);
	cube->player->plane_length = tan(CAMERA_FOV / 2 * M_PI / 180.0);
	cube->player->planex = -1 * cube->player->player_dir_y
		* cube->player->plane_length;
	cube->player->planey = cube->player->player_dir_x
		* cube->player->plane_length;
}

void	dir_parse(t_cube *cube)
{
	int		i;
	char	*line_copy;

	i = 0;
	while (cube->map->full_map[i])
	{
		line_copy = cube->map->full_map[i];
		while (*line_copy == 32)
			line_copy++;
		if (ft_strncmp("NO", line_copy, 2) == 0 || ft_strncmp("SO", line_copy,
				2) == 0 || ft_strncmp("WE", line_copy, 2) == 0
			|| ft_strncmp("EA", line_copy, 2) == 0 || *line_copy == 'F'
			|| *line_copy == 'C')
			parse_map_struct(cube, line_copy);
		else if (*line_copy == '0' || *line_copy == '1')
		{
			digit_map_parse(cube, i);
			break ;
		}
		else if (*line_copy != '\0')
			print_error_close_window(cube, "input map error");
		i++;
	}
}
