/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:45:38 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 13:47:05 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_map_name(t_cube *cube, char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (argv[len - 1] != 'b' || argv[len - 2] != 'u' || argv[len - 3] != 'c'
		|| argv[len - 4] != '.')
		print_error_close_window(cube, "Map name error");
}

void	check_map_struct(t_cube *cube)
{
	if (!cube->map->north || !cube->map->south || !cube->map->west
		|| !cube->map->east || !cube->map->floor || !cube->map->ceiling)
		print_error_close_window(cube, "Map structure error");
}

void	check_map_closed_elements(t_cube *cube)
{
	int		line_index;
	char	**map;

	line_index = 0;
	map = cube->map->digit_map_copy;
	check_dif_size_line(cube);
	while (map[line_index])
	{
		if (line_index == 0 || line_index == cube->map->digit_map_height - 1)
			check_first_last_line(cube, line_index);
		else
			check_map_line(cube, line_index);
		line_index++;
	}
}

void	check_dif_size_line(t_cube *cube)
{
	int		i;
	size_t	size;

	i = 1;
	size = 0;
	while (cube->map->digit_map_copy[i])
	{
		size = ft_strlen(cube->map->digit_map_copy[i - 1]);
		if (ft_strlen(cube->map->digit_map_copy[i]) > size)
			check_diff_part(cube, i, size);
		else if (ft_strlen(cube->map->digit_map_copy[i]) < size)
			check_diff_part(cube, i - 1,
				ft_strlen(cube->map->digit_map_copy[i]));
		i++;
	}
}
