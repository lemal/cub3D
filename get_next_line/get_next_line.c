/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:07:26 by dmacmill          #+#    #+#             */
/*   Updated: 2022/11/01 12:34:35 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_line(char *str)
{
	int	i;

	i = 0;
	if (str[i] && str[i + 1] && str[i] == '\n' && str[i + 1] == '\n')
		return (1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

void	clear_str(char **buffer)
{
	char	*str;
	char	*buf;
	int		len;
	int		i;

	len = 0;
	i = 0;
	buf = *buffer;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] && buf[i] == '\n')
		i++;
	while (buf[len])
		len++;
	str = ft_substr_gnl(*buffer, i, len);
	free(*buffer);
	*buffer = str;
}

int	read_file(int fd, char **buffer)
{
	int		read_symb;
	char	*str;
	char	*p;

	str = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (0);
	while (check_line(str) == -1)
	{
		read_symb = read(fd, str, BUFFER_SIZE);
		if (read_symb <= 0)
		{
			free(str);
			return (read_symb);
		}
		str[read_symb] = '\0';
		p = ft_strjoin_gnl(*buffer, str);
		free(*buffer);
		*buffer = p;
	}
	free(str);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*str;

	(void) str;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
	{
		buffer = malloc(sizeof(char) * 1);
		if (!buffer)
			return (NULL);
		buffer[0] = 0;
	}
	else
		clear_str(&buffer);
	if (read_file(fd, &buffer) == -1)
		return (0);
	if (*buffer == 0)
	{
		free(buffer);
		buffer = 0;
		return (NULL);
	}
	return (ft_substr_gnl(buffer, 0, check_line(buffer)));
}
