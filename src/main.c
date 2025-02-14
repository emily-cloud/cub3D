/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 14:40:42 by hai               #+#    #+#             */
/*   Updated: 2025/01/29 10:49:29 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int argc, char **argv)
{
	t_cube	*cube;

	if (argc != 2)
	{
		printf("Error\nInvalid number of arguments\n");
		exit(EXIT_FAILURE);
	}
	cube = malloc(sizeof(t_cube));
	if (!cube)
		print_error_close_window(cube, "Memory allocation error");
	init_cube_data(cube);
	parse_map(cube, argv[1]);
	start_game(cube);
	exit(EXIT_SUCCESS);
}
