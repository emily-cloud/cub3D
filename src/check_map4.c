/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:49:36 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 13:49:55 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_start_end_number(t_cube *cube, int line_index)
{
	char	*map_line;
	int		start;
	int		end;

	map_line = cube->map->digit_map_copy[line_index];
	end = ft_strlen(map_line) - 1;
	start = 0;
	while (map_line[start] == 32)
		start++;
	while (map_line[end] == 32)
		end--;
	if (map_line[start] != '1' || map_line[end] != '1')
		print_error_close_window(cube, "Map is not closed ");
}
