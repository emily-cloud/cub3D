/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:22:48 by hai               #+#    #+#             */
/*   Updated: 2025/01/07 10:24:55 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <string.h>
#include "libft.h"

//#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc(ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*int main() {
    const char *original = "Hello, World!";
    char *duplicate;
    char *ft_duplicate;

    // Use strdup to create a duplicate of the original string
    duplicate = strdup(original);
    ft_duplicate = ft_strdup(original);

    if (duplicate == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return (1);
    }

    if (ft_duplicate == NULL) {
        fprintf(stderr, "ft_Memory allocation failed\n");
        return (1);
    }


    // Print the original and duplicated strings
    printf("Original: %s\n", original);
    printf("Duplicate: %s\n", duplicate);
    printf("ft_Duplicate: %s\n", ft_duplicate);

    // Free the memory allocated by strdup
    free(duplicate);
    free(ft_duplicate);

    return (0);
}*/
