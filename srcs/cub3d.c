/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:26:51 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/27 17:32:20 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map(t_type *var)
{
	var->map = "1111111\n1000001\n1010001\n11000N1\n1111111";
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