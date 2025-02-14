/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:15:57 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 14:16:19 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_texture_array(uint32_t **buffer)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(buffer[i]);
		i++;
	}
	free(buffer);
}

void	free_image_struct(t_img *image, void *mlx)
{
	if (image->img && mlx)
	{
		mlx_destroy_image(mlx, image->img);
		image->img = NULL;
	}
	free(image);
}
