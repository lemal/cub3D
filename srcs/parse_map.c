/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:34:27 by dmacmill          #+#    #+#             */
/*   Updated: 2022/11/01 12:27:41 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	strlen_without_aftspace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	cpy_new_map(char **map, char **new_map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		while (j < len)
		{
			if (ft_strlen(map[i]) > (size_t)j && map[i][j] != '\n')
				new_map[i][j] = map[i][j];
			j++;
		}
		free(map[i]);
		i++;
		j = 0;
	}
	free(map);
}

char	**new_rect_map(char **map, int fd)
{
	int		i;
	int		len;
	char	**rect_map;

	i = -1;
	len = strlen_without_aftspace(map[0]);
	while (map[++i])
	{
		if (len < strlen_without_aftspace(map[i]))
			len = strlen_without_aftspace(map[i]);
	}
	rect_map = (char **)malloc(sizeof(char *) * (rows_map(map) + 1));
	if (!rect_map)
		clean_map(map, fd, "Error malloc\n");
	rect_map[rows_map(map)] = 0;
	while (--i >= 0)
	{
		rect_map[i] = malloc(sizeof(char) * (len + 1));
		if (!rect_map[i])
			clean_map(map, fd, "Error malloc\n");
	}
	init_map_space(rect_map, len);
	cpy_new_map(map, rect_map, len);
	return (rect_map);
}

char	**init_map(int fd)
{
	char	**map;
	int		i;

	i = 0;
	(void) i;
	map = (char **)malloc(sizeof(char *) * 1);
	if (!map)
		clean_map(map, fd, "Error malloc\n");
	map[0] = NULL;
	while (catch_null_gnl_map(&map, fd))
		;
	if (rows_map(map) == 0)
	{
		free(map);
		return (NULL);
	}
	return (map);
}

void	parse_map(t_data *data, int fd)
{
	char	**map;

	map = init_map(fd);
	if (map)
		map = new_rect_map(map, fd);
	if (map && ft_check_map(map) == -1)
		clean_map(map, fd, "");
	if (map)
		data->map = matr_to_arr(map);
	if (map)
		end_map(map, fd);
}
