/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarton <mcarton@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:32:23 by mcarton           #+#    #+#             */
/*   Updated: 2025/03/25 13:59:22 by mcarton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	initialize_buffer(char **line)
{
	if (!*line)
	{
		*line = malloc(1);
		if (!*line)
			return ((void) NULL);
		(*line)[0] = '\0';
	}
}

static char	*update_buffer(char *buff)
{
	size_t	i;
	size_t	len;
	char	*newbuff;

	len = 0;
	i = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (buff[len] == '\n')
		len++;
	if (buff[len] == '\0')
		return (free(buff), NULL);
	newbuff = malloc(gnl_strlen(buff) - len + 1);
	if (!newbuff)
		return (free(buff), NULL);
	while (buff[len])
		newbuff[i++] = buff[len++];
	newbuff[i] = '\0';
	free(buff);
	return (newbuff);
}

static char	*extract_line(char *buff)
{
	size_t	len;
	size_t	i;
	char	*line;

	len = 0;
	i = 0;
	while (buff[len] && buff[len] != '\n')
		len++;
	if (buff[len] == '\n')
		len++;
	line = malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = buff[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*read_buffer(int fd, char **line)
{
	int		nbyte;
	char	*tempbuff;
	char	*newline;

	nbyte = 1;
	initialize_buffer(line);
	if (*line == NULL)
		return (NULL);
	while (!(gnl_strchr(*line, '\n')) && nbyte > 0)
	{
		tempbuff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!tempbuff)
			return (ft_free(line), free(tempbuff), NULL);
		nbyte = read(fd, tempbuff, BUFFER_SIZE);
		if (nbyte == -1)
			return (free(tempbuff), ft_free(line), NULL);
		tempbuff[nbyte] = '\0';
		newline = gnl_strjoin(*line, tempbuff);
		if (newline == NULL)
			return (free(tempbuff), ft_free(line), line = NULL, NULL);
		ft_free(line);
		*line = newline;
		free(tempbuff);
	}
	return (*line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer = NULL;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_buffer(fd, &buffer);
	if (!buffer || buffer[0] == '\0')
	{
		ft_free(&buffer);
		return (NULL);
	}
	line = extract_line(buffer);
	if (!line)
		return (ft_free(&buffer), NULL);
	buffer = update_buffer(buffer);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd;
	char *line;

	if (argc != 2)
		return (1);
	fd = open(argv[1], O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (0);
}
*/
