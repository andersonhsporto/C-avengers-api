/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anhigo-s <anhigo-s@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/28 00:39:01 by anhigo-s          #+#    #+#             */
/*   Updated: 2022/02/25 16:49:23 by anhigo-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*gnl_strjoinfree(char *s1, char *s2)
{
	char	*nstring;
	size_t	i;
	size_t	a;

	nstring = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	i = 0;
	a = 0;
	if (nstring == 0)
		return (0);
	while (s1[i] != '\0')
	{
		nstring[i] = s1[i];
		i++;
	}
	while (s2[a] != '\0')
	{
		nstring[i + a] = s2[a];
		a++;
	}
	nstring[i + a] = '\0';
	free(s1);
	s1 = NULL;
	return (nstring);
}

static char	*get_line(char **buffer_backup, size_t i)
{
	char	*line;
	char	*temp;

	while (((*buffer_backup)[i] != '\n') && ((*buffer_backup)[i] != '\0'))
		i++;
	if ((*buffer_backup)[i] == 0)
	{
		line = ft_strdup(*buffer_backup);
		free(*buffer_backup);
		*buffer_backup = NULL;
	}
	else
	{
		line = ft_substr(*buffer_backup, 0, i + 1);
		temp = ft_strdup(&(*buffer_backup)[i + 1]);
		free(*buffer_backup);
		*buffer_backup = NULL;
		if (*temp)
			*buffer_backup = ft_strdup(temp);
		free(temp);
		temp = NULL;
	}
	return (line);
}

static char	*get_next(int fd, ssize_t bytes_read, char *temp_buff)
{
	static char	*s_buffer;
	char		*temp;

	while (bytes_read > 0)
	{
		temp_buff[bytes_read] = '\0';
		if (s_buffer == 0)
			s_buffer = ft_strdup("");
		temp = ft_strdup(s_buffer);
		free(s_buffer);
		s_buffer = gnl_strjoinfree(temp, temp_buff);
		if (ft_strchr(s_buffer, '\n'))
			break ;
		bytes_read = read(fd, temp_buff, BUFFER_SIZE);
	}
	if (bytes_read == 0 && s_buffer == 0)
		return (NULL);
	return (get_line(&s_buffer, 0));
}

char	*get_next_line(int fd)
{
	char		temp_buff[BUFFER_SIZE + 1];
	ssize_t		bytes_read;

	if ((fd < 0) || (BUFFER_SIZE < 1) || (read(fd, temp_buff, 0) < 0))
		return (NULL);
	bytes_read = read(fd, temp_buff, BUFFER_SIZE);
	if (bytes_read < 0)
		return (NULL);
	return (get_next(fd, bytes_read, temp_buff));
}
