/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/27 19:32:40 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


bool	ft_incr_x(t_type *var, float x)
{
	var->r_dx += 5;
	if (ft_compare_color(var, BLUE) || ft_compare_color(var, PLAYER))
	{
		var->r_dx = x;
		if (var->top_left || var->bot_left)
		{
			var->env_color = YELLOW;
			return (true);
		}
		return (false);
	}
	var->r_dx = x;
	return (false);
}

bool	ft_decr_x(t_type *var, float x)
{
	var->r_dx -= 5;
	if (ft_compare_color(var, BLUE) || ft_compare_color(var, PLAYER))
	{
		var->r_dx = x;
		if (var->top_right || var->bot_right)
		{	
			var->env_color = WHITE;
			return  (true);
		}
		return (false);
	}
	var->r_dx = x;
	return (false);
}

bool	ft_incr_y(t_type *var, float y)
{
	var->r_dy += 5;
	if (ft_compare_color(var, BLUE) || ft_compare_color(var, PLAYER))
	{
		var->r_dy = y;
		if (var->top_left || var->top_right)
		{
			var->env_color = ORANGE;
			return (true);
		}
		return (false);
	}
	var->r_dy = y;
	return (false);
}


bool	ft_decr_y(t_type *var, float y)
{
	var->r_dy -= 5;
	if (ft_compare_color(var, BLUE) || ft_compare_color(var, PLAYER))
	{
		var->r_dy = y;
		if (var->bot_left || var->bot_right)
		{
			var->env_color = BLACK;
			return (true);
		}
		return (false);
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
	// ft_incr_x(var, x);//ft_corners(var, x, y)
	// ft_decr_x(var, x);
	// ft_incr_y(var, y);
	// ft_decr_y(var, y);
	// ft_corner_checks(var, x, y);
}


//wierdness

// bool	ft_incr_x(t_type *var, float x)
// {
// 	var->r_dx += 5;
// 	if (ft_compare_color(var, BLUE))
// 	{
// 		var->r_dx = x;
// 		var->env_color = BLACK;
// 		return (true);
// 	}
// 	var->r_dx = x;
// 	return (false);
// }

// bool	ft_decr_x(t_type *var, float x)
// {
// 	var->r_dx -= 5;
// 	if (ft_compare_color(var, BLUE))
// 	{
// 		var->r_dx = x;
// 		var->env_color = YELLOW;
// 		return (true);
// 	}
// 	var->r_dx = x;
// 	return (false);
// }

// bool	ft_incr_y(t_type *var, float y)
// {
// 	var->r_dy += 5;
// 	if (ft_compare_color(var, BLUE))
// 	{
// 		var->r_dy = y;
// 		var->env_color = ORANGE;
// 		return (true);
// 	}
// 	var->r_dy = y;
// 	return (false);
// }


// bool	ft_decr_y(t_type *var, float y)
// {
// 	var->r_dy -= 5;
// 	if (ft_compare_color(var, BLUE))
// 	{
// 		var->r_dy = y;
// 		var->env_color = WHITE;
// 		return (true);
// 	}
// 	var->r_dy = y;
// 	return (false);
// }

// void	ft_select_top_left(t_type *var, int bot, int right)
// {
// 	int	x;

// 	x = var->r_dx;
// 	var->r_dx += 5;
// 	if (ft_compare_color(var, BLUE))
// 	{
// 		var->r_dx = x;
// 		var->env_color = right;
// 		return ;
// 	}
// 	var->env_color = bot;
// 	var->r_dx = x;
// }

// void	ft_select_top_right(t_type *var, int bot, int left)
// {
// 	int	x;

// 	x = var->r_dx;
// 	var->r_dx -= 5;
// 	if (ft_compare_color(var, BLUE))
// 	{
// 		var->r_dx = x;
// 		var->env_color = left;
// 		return ;
// 	}
// 	var->env_color = bot;
// 	var->r_dx = x;
// }

// void	ft_select_bot_left(t_type *var, int top, int right)
// {
// 	int	y;

// 	y = var->r_dy;
// 	var->r_dy -= 5;
// 	if (ft_compare_color(var, BLUE))
// 	{
// 		var->r_dy = y;
// 		var->env_color = top;
// 		return ;
// 	}
// 	var->env_color = right;
// 	var->r_dy = y;
// }

// void	ft_select_bot_right(t_type *var, int top, int left)
// {
// 	int	y;

// 	y = var->r_dy;
// 	var->r_dy -= 5;
// 	if (ft_compare_color(var, BLUE))
// 	{
// 		var->r_dy = y;
// 		var->env_color = top;
// 		return ;
// 	}
// 	var->env_color = left;
// 	var->r_dy = y;
// }

// void	ft_wall_select(t_type *var)
// {
// 	if (var->top_left)
// 		ft_select_top_left(var, ORANGE, YELLOW);
// 	else if (var->top_right)
// 		ft_select_top_right(var, WHITE, ORANGE);
// 	else  if (var->bot_left)
// 		ft_select_bot_left(var, BLACK, YELLOW);
// 	else  if (var->bot_left)
// 		ft_select_bot_right(var, BLACK, WHITE);
// }


//working without corners
// bool	ft_incr_x(t_type *var, float x)
// {
// 	var->r_dx += 5;
// 	if (ft_compare_color(var, BLUE))
// 	{
// 		var->r_dx = x;
// 		var->env_color = BLACK;
// 		return (true);
// 	}
// 	var->r_dx = x;
// 	return (false);
// }

// bool	ft_decr_x(t_type *var, float x)
// {
// 	var->r_dx -= 5;
// 	if (ft_compare_color(var, BLUE))
// 	{
// 		var->r_dx = x;
// 		var->env_color = YELLOW;
// 		return (true);
// 	}
// 	var->r_dx = x;
// 	return (false);
// }

// bool	ft_incr_y(t_type *var, float y)
// {
// 	var->r_dy += 5;
// 	if (ft_compare_color(var, BLUE))
// 	{
// 		var->r_dy = y;
// 		var->env_color = ORANGE;
// 		return (true);
// 	}
// 	var->r_dy = y;
// 	return (false);
// }


// bool	ft_decr_y(t_type *var, float y)
// {
// 	var->r_dy -= 5;
// 	if (ft_compare_color(var, BLUE))
// 	{
// 		var->r_dy = y;
// 		var->env_color = WHITE;
// 		return (true);
// 	}
// 	var->r_dy = y;
// 	return (false);
// }

// void	ft_wall_select(t_type *var, float x, float y)
// {
// 	if (ft_incr_x(var, x))
// 		return ;//ft_corners(var, x, y)
// 	else if (ft_decr_x(var, x))
// 		return ;
// 	else if (ft_incr_y(var, y))
// 		return ;
// 	else if (ft_decr_y(var, y))
// 		return ;
// 	// ft_corner_checks(var, x, y);
// }