/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:59:08 by ygao              #+#    #+#             */
/*   Updated: 2025/01/29 10:22:30 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_map_lines(t_cube *cube, int fd)
{
	int		map_lines;
	char	*line;

	(void)cube;
	map_lines = 1;
	line = get_next_line(fd);
	while (line)
	{
		map_lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (map_lines);
}

void	get_map_width(t_cube *cube)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (cube->map->digit_map[i])
	{
		j = 0;
		while (cube->map->digit_map[i][j])
			j++;
		if (j > max)
			max = j;
		i++;
	}
	cube->map->map_width = max;
}

void	read_full_map(t_cube *cube, char *argv)
{
	char	*line;
	int		i;
	int		fd;

	i = 0;
	fd = open(argv, O_RDONLY);
	cube->map->full_map = (char **)malloc((cube->map->map_lines + 1)
			* sizeof(char *));
	if (!cube->map->full_map)
		print_error_close_window(cube, "Memory allocation error");
	while (i < cube->map->map_lines)
	{
		line = get_next_line(fd);
		cube->map->full_map[i] = ft_strdup_nl(line);
		free(line);
		i++;
	}
	cube->map->full_map[cube->map->map_lines] = NULL;
}

void	copy_map_line_dir(t_cube *cube, char *line_copy, char *s)
{
	line_copy += ft_strlen(s);
	while (*line_copy == 32)
		line_copy++;
	if (ft_strcmp(s, "NO") == 0)
	{
		cube->map->north = ft_strdup(line_copy);
		cube->map->north_flag = true;
	}
	else if (ft_strcmp(s, "SO") == 0)
	{
		cube->map->south = ft_strdup(line_copy);
		cube->map->south_flag = true;
	}
	else if (ft_strcmp(s, "WE") == 0)
	{
		cube->map->west = ft_strdup(line_copy);
		cube->map->west_flag = true;
	}
	else if (ft_strcmp(s, "EA") == 0 || *s == 'F' || *s == 'C')
		copy_map_line_dir_2(cube, line_copy, s);
	else
		print_error_close_window(cube, "input map error");
}

void	copy_map_line_dir_2(t_cube *cube, char *line_copy, char *s)
{
	if (ft_strcmp(s, "EA") == 0)
	{
		cube->map->east = ft_strdup(line_copy);
		cube->map->east_flag = true;
	}
	else if (ft_strcmp(s, "F") == 0)
	{
		cube->map->floor = ft_strdup(line_copy);
		cube->map->floor_flag = true;
	}
	else if (ft_strcmp(s, "C") == 0)
	{
		cube->map->ceiling = ft_strdup(line_copy);
		cube->map->ceiling_flag = true;
	}
}
