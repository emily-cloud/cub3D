/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 22:40:29 by hai               #+#    #+#             */
/*   Updated: 2023/11/24 22:44:04 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>
//#include <stdio.h>

#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}
