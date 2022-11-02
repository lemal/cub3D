/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:20:31 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/29 14:01:57 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	clean_map(char **map, int fd, char *str)
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
	ft_warn(str);
}

int	count_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ')
		i++;
	return (i);
}

void	clean_temp_arr(char **temp_arr, int i, int fd, char *str)
{
	while (i < 6)
	{
		free(temp_arr[i]);
		i++;
	}
	free(temp_arr);
	close(fd);
	ft_warn(str);
}

void	parse_numbers(int *data, char *str, int info_num, int info_zap)
{
	if (info_num == 1 && info_zap == 0)
	{
		if (data[0] == -1)
			data[0] = ft_atoi(str);
		else if (data[1] == -1)
			data[1] = ft_atoi(str);
		else if (data[2] == -1)
			data[2] = ft_atoi(str);
		else
			data[0] = -2;
	}
}

int	parse_color(int *data, char **arr, int index, int fd)
{
	int	i;
	int	info_num;
	int	info_zap;

	i = 2 + count_space(arr[index]) - 1;
	info_num = 0;
	info_zap = 0;
	while (arr[index][++i] && ((arr[index][i] >= '0' && arr[index][i] <= '9') ||
		arr[index][i] == ',' || arr[index][i] == ' '))
	{
		if (arr[index][i] >= '0' && arr[index][i] <= '9')
			info_num++;
		else
			info_num = 0;
		if (arr[index][i] == ',')
			info_zap++;
		else
			info_zap = 0;
		if (info_num > 3 || info_zap > 1)
			clean_temp_arr(arr, index, fd, "Error in the commas or numbers\n");
		parse_numbers(data, arr[index] + i, info_num, info_zap);
	}
	if (arr[index][i] != '\n')
		clean_temp_arr(arr, index, fd, "Incorrect char in color\n");
	return (0);
}
