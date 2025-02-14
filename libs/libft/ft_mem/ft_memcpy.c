/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 10:47:32 by hai               #+#    #+#             */
/*   Updated: 2023/11/24 21:48:19 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*char_dest;
	char	*char_src;

	char_dest = (char *)dest;
	char_src = (char *)src;
	i = 0;
	if (dest == NULL && src == NULL)
		return (dest);
	while (i < n)
	{
		char_dest[i] = char_src[i];
		i++;
	}
	return (dest);
}
/*
int main()
{
    char src[] = "Hello, World!";
    char dest[20];

    // Using ft_memcpy to copy the content of src to dest
    ft_memcpy(dest, src, 8);
    // Print the resulting string
    printf("After ft_memcpy: %s\n", dest);

    memcpy(dest, src, 8);
    printf("After memcpy: %s\n", dest);

    return 0;
}*/
