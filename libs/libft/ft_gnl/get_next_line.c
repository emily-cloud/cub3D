/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hai <hai@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:57:42 by hai               #+#    #+#             */
/*   Updated: 2024/05/18 11:30:53 by hai              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*remain;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buffer);
		free(remain);
		remain = NULL;
		buffer = NULL;
		return (NULL);
	}
	line = read_line(fd, remain, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	remain = cut_line(line);
	return (line);
}

char	*read_line(int fd, char *remain, char *buffer)
{
	int		bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(remain), NULL);
		else if (bytes_read == 0)
			break ;
		buffer[bytes_read] = 0;
		if (!remain)
			remain = ft_strdup("");
		temp = remain;
		remain = ft_strjoin(remain, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (remain);
}

char	*cut_line(char *line)
{
	size_t	i;
	char	*remain;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\0')
		return (NULL);
	remain = ft_substr(line, i + 1, ft_strlen(line) - i - 1);
	if (*remain == '\0')
	{
		free(remain);
		remain = NULL;
	}
	line[i + 1] = '\0';
	return (remain);
}
