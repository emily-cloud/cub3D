/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 09:22:43 by hai               #+#    #+#             */
/*   Updated: 2023/11/29 12:35:23 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//#include <stdio.h>
//#include <string.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char	uc1;
	unsigned char	uc2;
	size_t			i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		uc1 = (unsigned char)s1[i];
		uc2 = (unsigned char)s2[i];
		if (uc1 != uc2)
			return (uc1 - uc2);
		i++;
	}
	return (0);
}
/*
int main()
{
    char s1[] = "acc";
    char s2[] = "accc";
    int result;
   
    result = ft_strncmp(s1, s2, 4);
   
    if (result ==0) {
        printf("The strings are equal.\n");
    } else if (result < 0) {
        printf("str1 is less than str2.\n");
    } else {
        printf("str1 is greater than str2.\n");}
    return (0);
}*/
