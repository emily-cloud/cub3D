/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:08:51 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 14:00:27 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map(t_cube *cube, char *argv)
{
	check_map_name(cube, argv);
	check_map_struct(cube);
	check_map_closed_elements(cube);
	check_map_player(cube);
	check_c_f(cube, "Floor");
	check_c_f(cube, "Ceiling");
}

void	check_c_f(t_cube *cube, char *str)
{
	char	*line;

	line = NULL;
	if (ft_strcmp(str, "Ceiling") == 0)
		line = ft_strdup(cube->map->ceiling);
	else if (ft_strcmp(str, "Floor") == 0)
		line = ft_strdup(cube->map->floor);
	check_c_f_line(cube, line);
	free(line);
}

void	check_c_f_line(t_cube *cube, char *line)
{
	int		number_count;
	int		comma_count;
	int		i;

	number_count = 0;
	comma_count = 0;
	i = 0;
	while (line[i])
	{
		if (ft_isdigit(line[i]))
		{
			number_count++;
			while (line[i] && ft_isdigit(line[i]))
				i++;
		}
		else if (line[i] == ',')
		{
			comma_count++;
			i++;
		}
		else
			i++;
	}
	if (number_count != 3 || comma_count != 2)
		print_error_close_window(cube, "Floor or Ceiling error");
}

void	check_map_player(t_cube *cube)
{
	int		i;
	int		player_count;
	char	**map;

	i = 0;
	player_count = 0;
	map = cube->map->digit_map_copy;
	while (map[i])
	{
		while (*map[i])
		{
			if (*map[i] == 'N' || *map[i] == 'S' || *map[i] == 'W'
				|| *map[i] == 'E')
			{
				player_count++;
				if (player_count > 1)
					print_error_close_window(cube, "More than one player");
			}
			map[i]++;
		}
		i++;
	}
}

void	check_diff_part(t_cube *cube, int i, size_t size)
{
	char	*line_copy;

	line_copy = cube->map->digit_map_copy[i];
	line_copy += size;
	while (*line_copy)
	{
		if (*line_copy == '0')
			print_error_close_window(cube, "Map is not closed");
		else if (*line_copy != '1' && *line_copy != ' ')
			print_error_close_window(cube, "Map includes invalid element");
		line_copy++;
	}
}
