/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 09:38:01 by hai               #+#    #+#             */
/*   Updated: 2023/11/28 10:32:26 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <bsd/string.h>

char	*ft_strnstr(char *str1, char *str2, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (str2[0] == '\0')
		return (str1);
	while (str1[i] != '\0' && i < len)
	{
		j = 0;
		while (str1[i + j] == str2[j] && i + j < len)
		{
			j++;
			if (str2[j] == '\0')
				return (str1 + i);
		}
		i++;
	}
	return (NULL);
}
/*
int main() {
    char *str1 = "Hello, World!";
    char *str2 = "or";
    char *test;

    // Test case 1: Find "World" in "Hello, World!"
    // test = ft_strnstr(str1, str2, -1);
char *test2 = strnstr(str1, str2, -6);
printf("%s\n",test2 );
    // if (test != NULL) {
    //     printf("Substring found: %s\n", test);
    // } else {
    //     printf("Substring not found\n");
    // }
    return 0;
}*/
