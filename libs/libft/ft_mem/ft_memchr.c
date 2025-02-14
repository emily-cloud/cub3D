/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:51:41 by hai               #+#    #+#             */
/*   Updated: 2023/11/29 12:40:57 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <string.h>

//#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*cs;
	unsigned char	uc;

	i = 0;
	cs = (unsigned char *)s;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (cs[i] == uc)
			return ((void *)(cs + i));
		i++;
	}
	return (NULL);
}
