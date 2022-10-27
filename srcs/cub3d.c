/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:26:51 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/26 17:33:43 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map(t_type *var)
{
	var->map = "11111111\n10000001\n10100001\n110000N1\n11111111";
}

int	main(void)
{
	t_type	var;

	ft_map(&var);
	if (!ft_mlx_setup(&var))
		return (1);
	ft_player_setup(&var);
	ft_game(&var);
	return (0);
}