/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/30 12:25:52 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_incr_x(t_type *var, float x)
{
	var->r_dx += 1;
	if (ft_compare_color(var, BLUE) || ft_compare_color(var, PLAYER))
	{
		var->r_dx = x;
		var->env_color = YELLOW;
		return (true);
	}
	var->r_dx = x;
	return (false);
}

bool	ft_decr_x(t_type *var, float x)
{
	var->r_dx -= 1;
	if (ft_compare_color(var, BLUE) || ft_compare_color(var, PLAYER))
	{
		var->r_dx = x;
		var->env_color = WHITE;
		return (true);
	}
	var->r_dx = x;
	return (false);
}

bool	ft_incr_y(t_type *var, float y)
{
	var->r_dy += 1;
	if (ft_compare_color(var, BLUE) || ft_compare_color(var, PLAYER))
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
	var->r_dy -= 1;
	if (ft_compare_color(var, BLUE) || ft_compare_color(var, PLAYER))
	{
		var->r_dy = y;
		var->env_color = BLACK;
		return (true);
	}
	var->r_dy = y;
	return (false);
}

void	ft_wall_select(t_type *var, float x, float y)
{
	bool	wall_right;
	bool	wall_left;
	bool	wall_top;
	bool	wall_bot;

	wall_right = ft_incr_x(var, x);
	wall_left = ft_decr_x(var, x);
	wall_top = ft_incr_y(var, y);
	wall_bot = ft_decr_y(var, y);
	if (wall_left && wall_top)
		var->env_color = BLACK;
	else if (wall_left && wall_bot)
		var->env_color = BLACK;
	if (wall_right && wall_top)
		var->env_color = BLACK;
	else if (wall_right && wall_bot)
		var->env_color = BLACK;
}
