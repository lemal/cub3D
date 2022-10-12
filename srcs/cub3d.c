/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:26:51 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/12 17:26:49 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_map(t_type *var)
{
	var->map = "111111\n100101\n101001\n1100N1\n111111";
}

int	main(void)
{
	t_type	var;
	
	ft_map(&var);
	if (!ft_mlx_setup(&var))
		return (1);
	ft_game(&var);
	return (0);
}