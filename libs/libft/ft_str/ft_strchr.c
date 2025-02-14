/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 11:17:14 by hai               #+#    #+#             */
/*   Updated: 2024/05/16 13:50:06 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <string.h>
//#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int			i;
	const char	*str;

	i = 0;
	while (s[i] != (char)c && s[i])
	{
		i++;
	}
	if (s[i] == 0 && (char)c != 0)
		str = NULL;
	else
		str = &s[i];
	return ((char *)str);
}

/*char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	if (c > 256)
		c = c % 256;
	if (c == '\0')
		return ((char *)(str + ft_strlen(str)));
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return ((char *)(str + i));
		i++;
	}
	return (NULL);
}*/
/*
int main() {
    char *str = "Hello, World!";
    int c = 'o';

    // Test case: Find 'W' in the string using ft_strchr
    char *result_ft_strchr = ft_strchr(str, c);
    if (result_ft_strchr != NULL) {
        printf("ft_strchr result: %s\n",result_ft_strchr);
    } else {
        printf("ft_strchr result:Character '%c' not found in the string.\n", c);
    }

    // Test case: Find 'W' in the string using strchr
    char *result_strchr = strchr(str, c);
    if (result_strchr != NULL) {
        printf("strchr result: %s\n", result_strchr);
    } else {
        printf("strchr result:Character '%c' not found in the string.\n", c);
    }

    return 0;
}*/
