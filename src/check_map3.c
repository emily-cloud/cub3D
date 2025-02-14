/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:47:50 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 14:26:57 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_first_last_line(t_cube *cube, int line_index)
{
	int		i;
	char	*map_line;

	i = 0;
	map_line = cube->map->digit_map_copy[line_index];
	check_start_end_number(cube, line_index);
	find_check_space(cube, line_index, &i);
	while (map_line[i])
	{
		if (map_line[i] == '1')
		{
			i++;
			continue ;
		}
		else if (map_line[i] == 32)
		{
			find_check_space(cube, line_index, &i);
			continue ;
		}
		else if (map_line[i] == '0')
			print_error_close_window(cube, "Map is not closed");
		else
			print_error_close_window(cube, "Map includes invalid element");
	}
}

void	check_map_line(t_cube *cube, int line_index)
{
	int		i;
	char	*map_line;

	i = 0;
	map_line = cube->map->digit_map_copy[line_index];
	check_start_end_number(cube, line_index);
	find_check_space(cube, line_index, &i);
	while (map_line[i])
	{
		if (map_line[i] == 32)
		{
			find_check_space(cube, line_index, &i);
			continue ;
		}
		else if (map_line[i] != '0' && map_line[i] != '1' && map_line[i] != 'N'
			&& map_line[i] != 'S' && map_line[i] != 'W' && map_line[i] != 'E')
		{
			print_error_close_window(cube, "Map includes invalid element");
		}
		i++;
	}
}

void	find_check_space(t_cube *cube, int line_index, int *i)
{
	int	space_start;
	int	j;

	space_start = -1;
	find_space_start(cube, i, line_index, &space_start);
	if (space_start != -1)
		check_space_surrounding(cube, line_index, space_start);
	line_index = 0;
	while (cube->map->digit_map_copy[line_index])
	{
		j = 0;
		while (cube->map->digit_map_copy[line_index][j])
		{
			if (cube->map->digit_map_copy[line_index][j] == '.')
				cube->map->digit_map_copy[line_index][j] = ' ';
			j++;
		}
		line_index++;
	}
}

void	find_space_start(t_cube *cube, int *i, int line_index, int *space_start)
{
	int		j;
	char	*map_line;

	j = *i;
	map_line = cube->map->digit_map_copy[line_index];
	while (map_line[j] == 32)
		j++;
	if (j > *i)
		*space_start = *i;
	*i = j;
}

void	check_space_surrounding(t_cube *cube, int line_index, int space_start)
{
	char	*map_line;

	if (line_index < 0 || line_index >= cube->map->digit_map_height
		|| space_start < 0
		|| space_start >= (int)ft_strlen(cube->map->digit_map_copy[line_index]))
		return ;
	map_line = cube->map->digit_map_copy[line_index];
	if (map_line[space_start] == '1' || map_line[space_start] == '.')
		return ;
	if (map_line[space_start] == '0')
		print_error_close_window(cube, "Map is not closed");
	if (map_line[space_start] == 'N' || map_line[space_start] == 'S'
		|| map_line[space_start] == 'W' || map_line[space_start] == 'E')
		print_error_close_window(cube, "Player must be surrounded by '1'");
	map_line[space_start] = '.';
	check_space_surrounding(cube, line_index - 1, space_start);
	check_space_surrounding(cube, line_index + 1, space_start);
	check_space_surrounding(cube, line_index, space_start - 1);
	check_space_surrounding(cube, line_index, space_start + 1);
}
