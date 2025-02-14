/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 08:45:14 by hai               #+#    #+#             */
/*   Updated: 2023/11/24 21:47:04 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

void	*ft_memset(void *dest, int c, size_t len)
{
	size_t	i;
	char	*ptr;

	ptr = dest;
	i = 0;
	while (i < len)
	{
		ptr[i] = c;
		i++;
	}
	return (dest);
}
/*
int	main()
{
	char str[20];
	char *result;
	char *test;
	// Using memset to initialize the array 'str' with 'A'
	memset(str, 'A', 20);
	result = (char *)memset(str, 'A', 20);
	printf("After memset: %s\n", str);
	printf("After memset: %p\n", result);

	// Using ft_memset to initialize the array 'str' with 'B'
	ft_memset(str, 'B', 20);
	test = (char *)ft_memset(str, 'B', 20);

	// Print the resulting string
	printf("After ft_memset: %s\n", str);
	printf("After ft_memset: %p\n", test);

	return 0;
}*/
