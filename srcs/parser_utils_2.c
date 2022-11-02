/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:56:04 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/29 15:01:48 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	empty_str_map(char **map)
{
	int	rw;
	int	i;
	int	j;

	i = 0;
	j = 0;
	rw = 0;
	while (map[i])
	{
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] != 0 && rw == 1)
			return (1);
		if (map[i][j] == 0)
			rw = 1;
		i++;
		j = 0;
	}
	rw = 1;
	return (0);
}

int	try_open(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	close(fd);
	return (0);
}

void	end_map(char **map, int fd)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	if (i != 0)
		free(map[i]);
	if (map)
		free(map);
	close(fd);
}
