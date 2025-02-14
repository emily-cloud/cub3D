/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42berlin.de>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 10:25:26 by hai               #+#    #+#             */
/*   Updated: 2023/12/03 10:55:43 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_new;
	int		i;
	int		len;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	str_new = (char *)malloc(sizeof(char) *(len + 1));
	if (!str_new)
		return (NULL);
	while (i < len)
	{
		str_new[i] = (*f)(i, s[i]);
		i++;
	}
	str_new[i] = '\0';
	return (str_new);
}
