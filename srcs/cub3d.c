/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:26:51 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/30 14:28:56 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map(t_type *var)
{
	var->map = "1111111\n1001001\n1100001\n10000N1\n1111111";
}

int	main(int argc, char **argv)
{
	t_type	var;

	(void) argv;
	if (argc != 1)
		return (0);
	ft_map(&var);
	if (!ft_ye_wall_colour(&var))
		return (0);
	if (!ft_mlx_setup(&var))
		return (0);
	ft_player_setup(&var);
	ft_game(&var);
	return (0);
}
