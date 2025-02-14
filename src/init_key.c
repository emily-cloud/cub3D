/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygao <ygao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 14:19:55 by ygao              #+#    #+#             */
/*   Updated: 2025/01/28 14:20:03 by ygao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_keys(t_cube *cube)
{
	cube->keys.w = false;
	cube->keys.a = false;
	cube->keys.s = false;
	cube->keys.d = false;
	cube->keys.left = false;
	cube->keys.right = false;
}
