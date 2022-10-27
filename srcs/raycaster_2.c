/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/27 15:56:24 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_incr_x(t_type *var, float x)
{
	var->r_dx += 5;
	if (ft_compare_color(var, BLUE))
	{
		var->r_dx = x;
		var->env_color = BLACK;
		return (true);
	}
	var->r_dx = x;
	return (false);
}

bool	ft_decr_x(t_type *var, float x)
{
	var->r_dx -= 5;
	if (ft_compare_color(var, BLUE))
	{
		var->r_dx = x;
		var->env_color = YELLOW;
		return (true);
	}
	var->r_dx = x;
	return (false);
}

bool	ft_incr_y(t_type *var, float y)
{
	var->r_dy += 5;
	if (ft_compare_color(var, BLUE))
	{
		var->r_dy = y;
		var->env_color = ORANGE;
		return (true);
	}
	var->r_dy = y;
	return (false);
}


bool	ft_decr_y(t_type *var, float y)
{
	var->r_dy -= 5;
	if (ft_compare_color(var, BLUE))
	{
		var->r_dy = y;
		var->env_color = WHITE;
		return (true);
	}
	var->r_dy = y;
	return (false);
}

void	ft_wall_select(t_type *var, float x, float y)
{
	if (ft_incr_x(var, x))
		return ;//ft_corners(var, x, y)
	else if (ft_decr_x(var, x))
		return ;
	else if (ft_incr_y(var, y))
		return ;
	else if (ft_decr_y(var, y))
		return ;
	// ft_corner_checks(var, x, y);
}
