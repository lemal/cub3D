/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmacmill <dmacmill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 18:23:18 by dmacmill          #+#    #+#             */
/*   Updated: 2022/10/29 14:57:12 by dmacmill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parser.h"

void	ft_warn(char *str)
{
	write(2, str, ft_strlen(str));
	exit(0);
}

void	check_initalize(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (data->rgb_c[i] < 0 || data->rgb_c[i] > 255)
			ft_warn("Error initalize ceiling!\n");
		if (data->rgb_f[i] < 0 || data->rgb_f[i] > 255)
			ft_warn("Error initalize floor!\n");
		i++;
	}
	if (!data->path_ea || !data->path_no || !data->path_so || !data->path_we)
		ft_warn("Error initalize directions!\n");
	if (try_open(data->path_ea) || try_open(data->path_no)
		|| try_open(data->path_so) || try_open(data->path_we))
		ft_warn("Error texture!\n");
}

int	check_file(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + len - 4, ".cub", 4) == 0)
		return (0);
	else
		return (1);
}

void	initalize(t_data *data)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		data->rgb_f[i] = -1;
		data->rgb_c[i] = -1;
		i++;
	}
	data->path_no = NULL;
	data->path_so = NULL;
	data->path_we = NULL;
	data->path_ea = NULL;
	data->map = NULL;
}
