/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:37:22 by dmacmill          #+#    #+#             */
/*   Updated: 2022/11/01 12:26:20 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	init_map_space(char **rect_map, int len)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (rect_map[i])
	{
		while (j < len)
		{
			rect_map[i][j] = ' ';
			j++;
		}
		rect_map[i][j] = '\0';
		i++;
		j = 0;
	}
}

int	catch_null_gnl_map(char ***map, int fd)
{
	char	*str;
	char	**temp_arr;
	int		i;

	i = -1;
	str = get_next_line(fd);
	if (str)
	{
		if (check_space_map(*map, str, fd))
			return (1);
		temp_arr = (char **)malloc(sizeof(char *) * (rows_map(*map) + 2));
		if (!temp_arr)
			clean_map(*map, fd, "Error malloc\n");
		while (*map && (*map)[++i])
			temp_arr[i] = (*map)[i];
		if (*map)
			free(*map);
		temp_arr[i] = str;
		temp_arr[i + 1] = 0;
		*map = temp_arr;
	}	
	else
		return (0);
	return (1);
}

int	check_space_map(char **map, char *str, int fd)
{
	(void) fd;
	if (check_empty_str(str) && rows_map(map) == 0)
	{
		free(str);
		return (1);
	}
	return (0);
}

void	more_25_lines(int *counter, int *len, char **map)
{
	counter[0] = 0;
	counter[1] = 0;
	counter[2] = 0;
	*len = rows_map(map) * (ft_strlen(map[0]) + 1);
}

char	*matr_to_arr(char **map)
{
	int		counter[3];
	int		len;
	char	*arr;

	more_25_lines(counter, &len, map);
	arr = malloc(sizeof(char) * len);
	if (!arr)
		return (NULL);
	while (map[counter[0]])
	{
		while (map[counter[0]][counter[1]])
		{
			arr[counter[2]] = map[counter[0]][counter[1]];
			counter[2]++;
			counter[1]++;
		}
		arr[counter[2]] = '\n';
		counter[2]++;
		counter[0]++;
		counter[1] = 0;
	}
	arr[counter[2] - 1] = 0;
	return (arr);
}
