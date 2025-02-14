/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 09:07:01 by hai               #+#    #+#             */
/*   Updated: 2025/01/28 14:32:56 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	close_window(t_cube *cube, char *s)
{
	free_all(cube);
	if (s)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	print_error_close_window(t_cube *cube, char *s)
{
	printf("%s\n", s);
	close_window(cube, "failed");
}

char	*ft_strdup_nl(char *s1)
{
	char	*dest;
	size_t	i;
	size_t	len;

	if (!s1)
		return (NULL);
	len = 0;
	i = 0;
	while (s1[len] && s1[len] != '\n')
		len++;
	dest = (char *)malloc(len + 1);
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[len] = 0;
	return (dest);
}

void	file_open_error(t_cube *cube, int fd)
{
	if (fd == -1)
		print_error_close_window(cube, "Error to open file");
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
