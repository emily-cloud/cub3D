/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:51:05 by hai               #+#    #+#             */
/*   Updated: 2023/11/27 10:03:45 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"
//#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (dest == NULL)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		dest[i] = s2[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main() {
    // Test case 1
    const char *s1 = "Hello, ";
    const char *s2 = "World!";
    char *result1 = ft_strjoin(s1, s2);
    printf("Result 1: %s\n", result1);
    free(result1); // Don't forget to free the memory allocated by ft_strjoin

    // Test case 2
    const char *s3 = "Testing ";
    const char *s4 = "ft_strjoin";
    char *result2 = ft_strjoin(s3, s4);
    printf("Result 2: %s\n", result2);
    free(result2); // Don't forget to free the memory allocated by ft_strjoin

    return 0;
}*/
