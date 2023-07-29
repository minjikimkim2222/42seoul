/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjiki2 <minjiki2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 08:59:49 by minjiki2          #+#    #+#             */
/*   Updated: 2023/07/29 21:15:55 by minjiki2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*make_line(char *backup)
{
	char	*p;
	int		idx;

	idx = 0;
	if (backup[0] == 0)
		return (NULL);
	while (backup[idx] != 0 && backup[idx++] != '\n')
		;
	p = (char *)malloc(idx + 1);
	if (!p)
		return (NULL);
	idx = 0;
	while (backup[idx] != '\0')
	{
		p[idx] = backup[idx];
		if (backup[idx++] == '\n')
			break ;
	}
	p[idx] = '\0';
	return (p);
}

char	*update_backup(char *backup)
{
	char	*ptr;
	int		idx1;
	int		idx2;

	idx1 = 0;
	idx2 = 0;
	while (backup[idx1] != '\0' && backup[idx1++] != '\n')
		;
	if (backup[idx1] == '\0')
	{
		free(backup);
		return (NULL);
	}
	ptr = (char *)malloc(ft_strlen(backup) - idx1 + 1);
	if (!ptr)
		return (NULL);
	while (backup[idx1] != '\0')
	{
		ptr[idx2] = backup[idx1];
		idx1++;
		idx2++;
	}
	ptr[idx2] = '\0';
	free(backup);
	return (ptr);
}

char	*read_set_backup(int fd, char *backup)
{
	char	*buff;
	int		ret;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	while (1)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == 0)
			break ;
		else if (ret == -1)
		{
			free(backup);
			backup = NULL;
			break ;
		}
		buff[ret] = '\0';
		if (backup == NULL)
			backup = ft_strdup(buff);
		else
			backup = append_string(backup, buff);
		if (ft_strchr(backup, '\n'))
			break ;
	}
	free(buff);
	return (backup);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	backup = read_set_backup(fd, backup);
	if (!backup)
		return (NULL);
	line = make_line(backup);
	backup = update_backup(backup);
	return (line);
}
