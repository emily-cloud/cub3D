/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 23:04:25 by hai               #+#    #+#             */
/*   Updated: 2023/11/27 09:20:30 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	char	*str;
	size_t	i;

	str = malloc(num * size);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < num * size)
	{
		str[i] = '\0';
		i++;
	}
	return (str);
}
/*int main() {
    // Example usage of your ft_calloc implementation
    char *arr;

    // Allocate and initialize memory for 5 characters
    arr = (char *)ft_calloc(5, sizeof(char));

    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Use the allocated memory as needed

    // Don't forget to free the allocated memory when done
    free(arr);

    return 0;
}*/
