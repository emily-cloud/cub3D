/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:08:56 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 14:09:22 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	calculate_delta_dist(t_cube *cube)
{
	if (cube->ray->ray_dir_x == 0)
		cube->ray->delta_dist_x = INFINITY;
	else
	{
		cube->ray->delta_dist_x = 1 / cube->ray->ray_dir_x;
		ft_abs(&cube->ray->delta_dist_x);
	}
	if (cube->ray->ray_dir_y == 0)
		cube->ray->delta_dist_y = INFINITY;
	else
	{
		cube->ray->delta_dist_y = 1 / cube->ray->ray_dir_y;
		ft_abs(&cube->ray->delta_dist_y);
	}
}
