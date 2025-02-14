/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 09:51:05 by hai               #+#    #+#             */
/*   Updated: 2023/11/29 11:25:29 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
// #include <string.h>
#include "libft.h"
// #include <stdlib.h>

char	*ft_substr(const char *str, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_str;
	size_t	len_sub;
	char	*substr;

	len_str = ft_strlen(str);
	if (str == NULL || len_str <= start)
		return (ft_strdup(""));
	len_sub = len_str - start;
	if (len_sub > len)
		len_sub = len;
	substr = (char *)malloc(len_sub +1);
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len_sub)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
/*int main() {
	const char *originalString = "Hello, World!";
	unsigned int start = 7;  // Start extracting from the 8th character
	size_t length = 5;       // Extract 5 characters

	char *substring = ft_substr(originalString, start, length);

	if (substring != NULL) {
		printf("Original String: %s\n", originalString);
		printf("Substring: %s\n", substring);
		free(substring);  // Remember to free the allocated memory
	} else {
		printf("Error: Unable to allocate memory for substring\n");
	}

	return 0;
}*/
