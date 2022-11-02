/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_elems.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:56:53 by dmacmill          #+#    #+#             */
/*   Updated: 2022/11/01 12:25:38 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

int	check_empty_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	if (str[i] == '\n')
		return (1);
	else
		return (0);
}

void	clean_error_arr(char **temp_arr, int i, int fd)
{
	i--;
	while (i >= 0)
	{
		free(temp_arr[i]);
		i--;
	}
	free(temp_arr);
	close(fd);
	ft_warn("Error number of elements in file\n");
}

char	*catch_null_gnl(int fd, int i, char **temp_arr)
{
	char	*str;

	str = get_next_line(fd);
	if (!str)
	{
		clean_error_arr(temp_arr, i, fd);
		ft_warn("Error malloc or folder!\n");
	}
	return (str);
}

char	**get_array_elems(int fd)
{
	char	*str;
	int		i;
	char	**temp_arr;

	i = 0;
	temp_arr = (char **)malloc(sizeof(char *) * 7);
	if (!temp_arr)
		ft_warn("Error malloc!\n");
	str = catch_null_gnl(fd, i, temp_arr);
	while (str && i < 6)
	{
		if (check_empty_str(str))
			free(str);
		else
		{
			temp_arr[i] = str;
			i++;
		}
		if (i < 6)
			str = catch_null_gnl(fd, i, temp_arr);
	}
	temp_arr[6] = 0;
	if (i != 6)
		clean_error_arr(temp_arr, i, fd);
	return (temp_arr);
}
