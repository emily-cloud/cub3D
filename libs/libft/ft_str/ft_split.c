/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 10:43:43 by hai               #+#    #+#             */
/*   Updated: 2023/12/04 10:44:50 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str)
	{
		if (*str != c)
		{
			count++;
			while (*str && *str != c)
				str++;
		}
		else
			str++;
	}
	return (count);
}

void	putstr(const char *s, char **strings, char c)
{
	const char		*start;
	int				j;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++; 
			strings[j] = ft_substr(start, 0, s - start);
			if (!strings[j++])
			{
				while (j-- >= 0)
					free(strings[j]);
				free(strings);
				return ;
			}
		}
		else
			s++;
	}
	strings[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	char			**strings;
	int				count;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	strings = (char **)malloc(sizeof(char *) * (count + 1));
	if (!strings)
		return (NULL);
	putstr(s, strings, c);
	return (strings);
}
