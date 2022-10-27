/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/27 20:01:12 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_top_left(t_type *var, float x, float y)
{
	if (var->p_x >= x && var->p_y >= y)
	{
		var->top_left = true;
		return (true);
	}
	return (false);
}

bool	ft_top_right(t_type *var, float x, float y)
{
	if (var->p_x <= x && var->p_y >= y)
	{
		var->top_right = true;
		return (true);
	}
	return (false);
}

bool	ft_bot_left(t_type *var, float x, float y)
{
	if (var->p_x >= x && var->p_y <= y)
	{
		var->bot_left = true;
		return (true);
	}
	return (false);
}

bool	ft_bot_right(t_type *var, float x, float y)
{
	if (var->p_x <= x && var->p_y <= y)
	{
		var->bot_right = true;
		return (true);
	}
	return (false);
}

void	ft_coordinate_checks(t_type *var, float	x, float y)
{
	float	temp_x;
	float	temp_y;
	
	var->bot_right = false;
	var->bot_left = false;
	var->top_right = false;
	var->top_left = false;
	temp_x = x + var->p_x;
	temp_y = y + var->p_y;
	// ft_wall_select(var, x, y);
	ft_top_left(var, temp_x, temp_y);
	ft_top_right(var, temp_x, temp_y);
	ft_bot_left(var, temp_x, temp_y);
	ft_bot_right(var, temp_x, temp_y);
	ft_wall_select(var, x, y);
}
