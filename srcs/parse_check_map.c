/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_check_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:32:02 by dmacmill          #+#    #+#             */
/*   Updated: 2022/11/01 12:23:33 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	rows_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i] != NULL)
		i++;
	return (i);
}

int	symb_hero(char c)
{
	if (c == 'N' || c == 'E' || c == 'W' || c == 'S')
		return (0);
	return (1);
}

int	check_rows_columns(char **map)
{
	int	i;
	int	j;
	int	symb;

	i = 0;
	j = 0;
	symb = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (symb_hero(map[i][j]) == 0)
				symb++;
			if (symb > 1 || (map[i][j] != '0' && map[i][j] != '1'
				&& map[i][j] != 'N' && map[i][j] != 'S' && map[i][j] != ' '
				&& map[i][j] != 'W' && map[i][j] != 'E'))
				return (-1);
			j++;
		}
		i++;
		j = 0;
	}
	if (symb == 0)
		return (-1);
	return (1);
}

int	check_null(char **map, int i, int j)
{
	if (map[i][j] == '0' || symb_hero(map[i][j]) == 0)
	{
		if (j == 0 || (size_t)j == ft_strlen(map[i]) || i == 0
			|| i == rows_map(map) - 1)
			return (-1);
		else if (map[i][j - 1] != '0' && map[i][j - 1] != '1'
			&& symb_hero(map[i][j - 1]))
			return (-1);
		else if (map[i - 1][j] != '0' && map[i - 1][j] != '1'
			&& symb_hero(map[i - 1][j]))
			return (-1);
		else if (map[i + 1][j] != '0' && map[i + 1][j] != '1'
			&& symb_hero(map[i + 1][j]))
			return (-1);
		else if (map[i][j + 1] != '0' && map[i][j + 1] != '1'
			&& symb_hero(map[i][j + 1]))
			return (-1);
	}
	return (0);
}

int	ft_check_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (check_rows_columns(map) == -1 || empty_str_map(map))
	{
		printf("Error char in map\n");
		return (-1);
	}
	while (map[i])
	{
		while (map[i][j])
		{
			if (check_null(map, i, j) == -1)
			{
				printf("Error map i = %d, j = %d\n", i, j);
				return (-1);
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (1);
}
