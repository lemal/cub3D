/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/24 17:59:53 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_colour_picker(t_type *var)
{
	if (var->horizontal)
	{
		if (var->p_look_angle < PI && var->p_look_angle > 0)
			var->env_color = BLACK;//^-
		else if (var->p_look_angle > PI && var->p_look_angle <= 2 * PI)
			var->env_color = ORANGE;//~_
	}
	else if (var->vertical)
	{
		if ((var->p_look_angle > 0 && var->p_look_angle <= PI / 2)
			|| (var->p_look_angle <= 2 * PI && var->p_look_angle >= (3 / 2) * PI))
			var->env_color = WHITE;// >-
		else if (var->p_look_angle > PI / 2 && var->p_look_angle < (3 / 2) * PI)
			var->env_color = YELLOW;// <-
	}
}

void	ft_wall_colour_set(t_type *var)
{
	var->horizontal = false;
	var->vertical = false;
	var->r_dx += 1;
	if (ft_check_surround(var, GREEN))
	{
		var->r_dx -= 2;
		if (ft_check_surround(var, GREEN))
			var->horizontal = true;
		var->r_dx += 1;
	}
	var->r_dy += 1;
	if (ft_check_surround(var, GREEN))
	{
		var->r_dy -= 2;
		if (ft_check_surround(var, GREEN))
			var->vertical = true;
		var->r_dy += 1;
	}
	ft_colour_picker(var);
}