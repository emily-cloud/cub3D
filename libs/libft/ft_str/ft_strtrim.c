/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:11:31 by hai               #+#    #+#             */
/*   Updated: 2023/12/01 10:50:13 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	charcheck(const char *str, const char c)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		i;
	char	*str_new;

	start = 0;
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && charcheck(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && charcheck(set, s1[end - 1]))
		end--;
	str_new = (char *)malloc(end - start + 1);
	if (!str_new)
		return (NULL);
	while (start < end)
		str_new[i++] = s1[start++];
	str_new[i] = '\0';
	return (str_new);
}
