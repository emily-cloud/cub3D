/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:05:23 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 14:03:28 by ygao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	parse_map(t_cube *cube, char *argv)
{
	if (!cube->mlx)
		print_error_close_window(cube, "Error to init mlx");
	get_map_data(cube, argv);
	check_map(cube, argv);
	convert_cf_rgb(cube, cube->map->floor, "Floor");
	convert_cf_rgb(cube, cube->map->ceiling, "Ceiling");
	load_texture(cube);
}

void	check_rgb_value(t_cube *cube, char *string, int i)
{
	if (i < 0 || i > 255)
	{
		print_error_close_window(cube, "RGB value error");
		free(string);
	}
}

void	convert_cf_rgb(t_cube *cube, char *str, char *s)
{
	char	**string;
	int		i;
	int		*rgb;

	string = ft_split(str, ',');
	if (!string)
		print_error_close_window(cube, "Memory allocation error");
	i = 0;
	rgb = malloc(sizeof(int) * 3);
	if (!rgb)
		print_error_close_window(cube, "Memory allocation error");
	while (i < 3)
	{
		rgb[i] = ft_atoi(string[i]);
		check_rgb_value(cube, string[i], rgb[i]);
		i++;
	}
	if (ft_strcmp(s, "Floor") == 0)
		cube->map->floor_color = ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
	else if (ft_strcmp(s, "Ceiling") == 0)
		cube->map->ceiling_color = ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
	free(rgb);
	free_split(string);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	get_map_data(t_cube *cube, char *argv)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	file_open_error(cube, fd);
	line = get_next_line(fd);
	if (!line)
	{
		free(line);
		close(fd);
		print_error_close_window(cube, "Empty map");
	}
	free(line);
	cube->map->map_lines = get_map_lines(cube, fd);
	read_full_map(cube, argv);
	dir_parse(cube);
	get_map_width(cube);
	close(fd);
}
