/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/27 18:30:34 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_top_left(t_type *var, float x, float y)
{
	if (var->p_x > x && var->p_y > y)
		var->top_left = true;
}

void	ft_top_right(t_type *var, float x, float y)
{
	if (var->p_x < x && var->p_y > y)
		var->top_right = true;
}

void	ft_bot_left(t_type *var, float x, float y)
{
	if (var->p_x > x && var->p_y < y)
		var->bot_left = true;
}

void	ft_bot_right(t_type *var, float x, float y)
{
	if (var->p_x < x && var->p_y < y)
		var->bot_right = true;
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

//unsure if works

// void	ft_top_left(t_type *var, float x, float y)
// {
// 	if (var->p_x > x && var->p_y > y)
// 	{
// 		if (var->env_color == WHITE)
// 			var->env_color = ORANGE;
// 		else if (var->env_color == BLACK)
// 			var->env_color = YELLOW;
// 	}
// }

// void	ft_top_right(t_type *var, float x, float y)
// {
// 	if (var->p_x < x && var->p_y > y)
// 	{
// 		if (var->env_color == BLACK)
// 			var->env_color = WHITE;
// 		else if (var->env_color == YELLOW)
// 			var->env_color = ORANGE;
// 	}
// }

// void	ft_bot_left(t_type *var, float x, float y)
// {
// 	if (var->p_x > x && var->p_y < y)
// 	{
// 		if (var->env_color == WHITE)
// 			var->env_color = BLACK;
// 		else if (var->env_color == ORANGE)
// 			var->env_color = YELLOW;
// 	}
// }

// void	ft_bot_right(t_type *var, float x, float y)
// {
// 	if (var->p_x < x && var->p_y < y)
// 	{
// 		if (var->env_color == ORANGE)
// 			var->env_color = WHITE;
// 		else if (var->env_color == YELLOW)
// 			var->env_color = BLACK;
// 	}
// }

// void	ft_coordinate_checks(t_type *var, float	x, float y)
// {
// 	float	temp_x;
// 	float	temp_y;

// 	temp_x = x + var->p_x;
// 	temp_y = y + var->p_y;
// 	ft_wall_select(var, x, y);
// 	ft_top_left(var, temp_x, temp_y);
// 	ft_top_right(var, temp_x, temp_y);
// 	ft_bot_left(var, temp_x, temp_y);
// 	ft_bot_right(var, temp_x, temp_y);
// }