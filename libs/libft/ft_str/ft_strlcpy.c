/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:54:42 by hai               #+#    #+#             */
/*   Updated: 2023/11/23 09:37:05 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (dest == NULL || size == 0)
		return (len_src);
	else
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
		return (len_src);
	}
}
/*int main()
{
    char dest[20];
    char src[] = "Hello, World!";
    unsigned int n = 10;

    // Call your ft_strlcpy function
    int length = ft_strlcpy(dest, src, n);

    // Print the result
    printf("Source: %s\n", src);
    printf("Destination (ft_strlcpy): %s\n", dest);
    printf("Length of source (ft_strlcpy): %d\n", length);

    return 0;
}*/
