/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:26:51 by tapulask          #+#    #+#             */
/*   Updated: 2022/11/02 16:06:05 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_api(t_data data, t_type *var)
{
	var->map = data.map;
	var->path_n = data.path_no;
	var->path_s = data.path_so;
	var->path_e = data.path_ea;
	var->path_w = data.path_we;
	var->ceil_col = ft_trgb(0, data.rgb_c[0], data.rgb_c[1], data.rgb_c[2]);
	var->floor_col = ft_trgb(0, data.rgb_f[0], data.rgb_f[1], data.rgb_f[2]);
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_type	var;

	if (argc == 1)
		return (0);
	parser(&data, argv[1]);
	ft_api(data, &var);
	if (!ft_ye_wall_colour(&var))
		return (0);
	if (!ft_mlx_setup(&var))
		return (0);
	ft_player_setup(&var);
	ft_game(&var);
	free(var.map);
	free(data.path_ea);
	free(data.path_no);
	free(data.path_we);
	free(data.path_so);
	return (0);
}
