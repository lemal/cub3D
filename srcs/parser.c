/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:37:03 by dmacmill          #+#    #+#             */
/*   Updated: 2022/11/01 16:26:28 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	aft(char *str)
{
	int	i;

	i = 2;
	while (str[i] && str[i] == ' ')
		i++;
	return (i);
}

int	dir(char *str)
{
	int	i;
	int	j;

	i = 2;
	j = 1;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i] && str[i] != ' ' && str[i] != '\n')
		i++;
	while (str[i] && str[i] == ' ')
	{
		i++;
		j++;
	}
	if (str[i] == '\n')
		return (j);
	else
		return (0);
}

void	parse_directions(t_data *data, char **a, int i)
{
	int	j;

	j = 0;
	while (a[i][j] == ' ')
		j++;
	if (ft_strncmp(a[i] + j, "NO ", 3) == 0 && dir(a[i] + j)
		&& ft_strncmp(a[i] + j + aft(a[i] + j), "./", 2) == 0)
			data->path_no = ft_substr(a[i] + j + aft(a[i] + j),
				2, ft_strlen(a[i] + j + aft(a[i] + j)) - dir(a[i] + j) - 2);
	if (ft_strncmp(a[i] + j, "SO ", 3) == 0 && dir(a[i] + j)
		&& ft_strncmp(a[i] + j + aft(a[i] + j), "./", 2) == 0)
			data->path_so = ft_substr(a[i] + j + aft(a[i] + j),
				2, ft_strlen(a[i] + j + aft(a[i] + j)) - dir(a[i] + j) - 2);
	if (ft_strncmp(a[i] + j, "WE ", 3) == 0 && dir(a[i] + j)
		&& ft_strncmp(a[i] + j + aft(a[i] + j), "./", 2) == 0)
			data->path_we = ft_substr(a[i] + j + aft(a[i] + j),
				2, ft_strlen(a[i] + j + aft(a[i] + j)) - dir(a[i] + j) - 2);
	if (ft_strncmp(a[i] + j, "EA ", 3) == 0 && dir(a[i] + j)
		&& ft_strncmp(a[i] + j + aft(a[i] + j), "./", 2) == 0)
			data->path_ea = ft_substr(a[i] + j + aft(a[i] + j),
				2, ft_strlen(a[i] + j + aft(a[i] + j)) - dir(a[i] + j) - 2);
}

void	parse_elems(t_data *data, int fd)
{
	char	**arr;
	int		i;
	int		j;

	arr = get_array_elems(fd);
	i = 0;
	while (arr[i] && i < 6)
	{
		j = 0;
		while (arr[i][j] == ' ')
			j++;
		parse_directions(data, arr, i);
		if (ft_strncmp(arr[i] + j, "F ", 2) == 0)
			parse_color(data->rgb_f, arr, i, fd);
		if (ft_strncmp(arr[i] + j, "C ", 2) == 0)
			parse_color(data->rgb_c, arr, i, fd);
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	parser(t_data *data, char *file)
{
	int	fd;

	if (check_file(file))
		ft_warn("Error! \"*.cub\" file required\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		ft_warn("Can't open file\n");
	initalize(data);
	parse_elems(data, fd);
	check_initalize(data);
	parse_map(data, fd);
	if (!data->map)
		ft_warn("Error map!\n");
	close(fd);
}
