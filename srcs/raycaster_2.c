/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/27 12:28:30 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	ft_top(t_type *var)
{
	if (var->r_angle > PI / 4 && var->r_angle <= 3 * PI / 4)
	{
		var->bot = true;
		if (var->r_angle > PI / 2)
			var->right = true;
		else
			var->left = true;
		return (true);
	}
	return (false);
}

bool	ft_left(t_type *var)
{
	if (var->r_angle > 3 * PI / 4 && var->r_angle <= 5 * PI / 4)
	{
		var->right = true;
		if (var->r_angle > PI)
			var->top = true;
		else
			var->bot = true;
		return (true);
	}
	return (false);
}

bool	ft_bot(t_type *var)
{
	if ((var->r_angle > 5 * PI / 4 && var->r_angle <= 7 * PI / 4)
		|| (var->r_angle > -PI / 2 && var->r_angle < -PI / 4))
	{
		var->top = true;
		if (var->r_angle > 3 * PI / 2 || var->r_angle < -PI / 4)//errors?
			var->left = true;
		else
			var->right = true;
		return (true);
	}
	return (false);
}

//negative outcomes may break this - assume none for now
bool	ft_right(t_type *var)
{
	if ((var->r_angle > 7 * PI / 4 && var->r_angle <= 2 * PI) // check the angle values lol
		|| (var->r_angle >= 0 && var->r_angle > PI / 4)
		|| (var->r_angle < 0 && var->r_angle >= -PI / 4))//errors?
	{
		var->left = true;
		if (var->r_angle <= 2 * PI)
			var->top = true;
		else
			var->bot = true;
		return (true);
	}
	return (false);
}

void	ft_set_wall_faces(t_type *var)
{
	var->top = false;
	var->bot = false;
	var->left = false;
	var->right = false;
	if (ft_top(var))
		return ;
	else if (ft_left(var))
		return ;
	else if (ft_bot(var))
		return ;
	else if (ft_right(var))
		return ;
}

// void	ft_coordinate_collector(t_type *var)
// {
// 	static call_count
// }

// void	ft_wall_faces(t_type *var)
// {
// 	//virtual coordinate firing
// 	//where the vc point? that wall that is hit, where is it facing?

// 	if (var->r_angle > PI / 4 && var->r_angle <= 3 * PI / 4)
// 	{
// 		if (var->r_angle > PI / 2)
		
// 		else
// 	}
// 		//find if horizontal or vertical line was hit by testing memory. 
// 		// var->env_color = BLACK;//^-
// 	else if (var->r_angle > 3 * PI / 4 && var->r_angle <= 5 * PI / 4)
// 	{
// 		if (var->r_angle > PI)
		
// 		else
// 	}
// 		// var->env_color = ORANGE;//~_
// 		// var->env_color = WHITE;// >-
// 	else if (var->r_angle > 5 * PI / 4 && var->r_angle <= 7 * PI / 4)
// 	{
// 		if (var->r_angle > 3 * PI / 2)
		
// 		else
// 	}
// 	else if ((var->r_angle > 7 * PI / 4 && var->r_angle <= 2 * PI) // check the angle values lol
// 		|| (var->r_angle >= 0 && var->r_angle > PI / 4))
// 	{
// 		if (var->r_angle < 2 * PI)

// 		else
// 	}
// 		// var->env_color = YELLOW;// <-
// 	// ft_hor_or_vert(var);

// }

// bool	ft_left_found(t_type *var)
// {
// 	int	i;
// 	int	depth;

// 	i = 0;
// 	depth = 25;
// 	while (i < depth)
// 	{
// 		var->r_dx -= i;
// 		if (ft_check_surround(var, BLUE))
// 		{
// 			var->r_dx += i;
// 			return (true);
// 		}
// 		var->r_dx += i;
// 		i++;
// 	}
// 	return (false);
// }

// bool	ft_right_found(t_type *var)
// {
// 	int	i;
// 	int	depth;

// 	i = 0;
// 	depth = 25;
// 	while (i < depth)
// 	{
// 		var->r_dx += i;
// 		if (ft_check_surround(var, BLUE))
// 		{
// 			var->r_dx -= i;
// 			return (true);
// 		}
// 		var->r_dx -= i;
// 		i++;
// 	}
// 	return (false);
// }

// bool	ft_top_found(t_type *var)
// {
// 	int	i;
// 	int	depth;

// 	i = 0;
// 	depth = 25;
// 	while (i < depth)
// 	{
// 		var->r_dy += i;
// 		if (ft_check_surround(var, BLUE))
// 		{
// 			var->r_dy -= i;
// 			return (true);
// 		}
// 		var->r_dy -= i;
// 		i++;
// 	}
// 	return (false);
// }

// bool	ft_bot_found(t_type *var)
// {
// 	int	i;
// 	int	depth;

// 	i = 0;
// 	depth = 25;
// 	while (i < depth)
// 	{
// 		var->r_dy -= i;
// 		if (ft_check_surround(var, BLUE))
// 		{
// 			var->r_dx += i;
// 			return (true);
// 		}
// 		var->r_dx += i;
// 		i++;
// 	}
// 	return (false);
// }

// void	ft_colour_setter(t_type	*var)
// {
// 	//find which one is blue, based on that - select the colour
// 	if (ft_left_found(var))
// 		var->env_color = YELLOW;
// 	else if (ft_right_found(var))
// 		var->env_color = BLACK;
// 	else if (ft_top_found(var))
// 		var->env_color = ORANGE;
// 	else if (ft_bot_found(var))
// 		var->env_color = WHITE;
// }

// void	ft_colour_setter(t_type	*var)
// {
// 	//find which one is blue, based on that - select the colour
// 	var->r_dx += 2;
// 	if (ft_check_surround(var, BLUE))
// 	{
// 		var->env_color = YELLOW;
// 		var->r_dx -= 2;
// 		return ;
// 	}
// 	var->r_dx -= 4;
// 	if (ft_check_surround(var, BLUE))
// 	{
// 		var->env_color = BLACK;
// 		var->r_dx += 2;
// 		return ;
// 	}
// 	var->r_dx += 2;
// 	var->r_dy += 2;
// 	if (ft_check_surround(var, BLUE))
// 	{
// 		var->env_color = ORANGE;
// 		var->r_dy -= 2;
// 		return ;
// 	}
// 	var->r_dy -= 4;
// 	if (ft_check_surround(var, BLUE))
// 	{
// 		var->env_color = WHITE;
// 		var->r_dy += 2;
// 		return ;
// 	}
// 	var->r_dy += 2;
// }

// void	ft_colour_picker(t_type *var)
// {
// 	if (var->horizontal)
// 	{
// 		var->env_color = BLACK;
// 		// if (var->r_angle < PI && var->r_angle > 0)
// 		// 	var->env_color = BLACK;//^-
// 		// else if (var->r_angle > PI && var->r_angle <= 2 * PI)
// 		// 	var->env_color = ORANGE;//~_
// 	}
// 	else if (var->vertical)
// 	{
// 		var->env_color = RED;
// 		// if ((var->r_angle > 0 && var->r_angle <= PI / 2)
// 		// 	|| (var->r_angle <= 2 * PI && var->r_angle >= (3 / 2) * PI))
// 		// 	var->env_color = WHITE;// >-
// 		// else if (var->r_angle > PI / 2 && var->r_angle < (3 / 2) * PI)
// 		// 	var->env_color = YELLOW;// <-
// 	}
// }

// // if (var->horizontal)
// // 	{
// // 		if (var->p_look_angle < PI && var->p_look_angle > 0)
// // 			var->env_color = BLACK;//^-
// // 		else if (var->p_look_angle > PI && var->p_look_angle <= 2 * PI)
// // 			var->env_color = ORANGE;//~_
// // 	}
// // 	else if (var->vertical)
// // 	{
// // 		if ((var->p_look_angle > 0 && var->p_look_angle <= PI / 2)
// // 			|| (var->p_look_angle <= 2 * PI && var->p_look_angle >= (3 / 2) * PI))
// // 			var->env_color = WHITE;// >-
// // 		else if (var->p_look_angle > PI / 2 && var->p_look_angle < (3 / 2) * PI)
// // 			var->env_color = YELLOW;// <-
// // 	}

// void	ft_wall_colour_set(t_type *var)
// {
// 	float	temp_1;
// 	float	temp_2;

// 	temp_1 = var->r_dx;
// 	temp_2 = var->r_dy;
// 	var->horizontal = false;//move dis to other func
// 	var->vertical = false;
// 	var->r_dx += 5;
// 	if (ft_check_surround(var, GREEN))
// 	{
// 		var->r_dx -= 10;
// 		if (ft_check_surround(var, GREEN))
// 			var->horizontal = true;
// 	}
// 	var->r_dx = temp_1;
// 	var->r_dy += 5;
// 	if (ft_check_surround(var, GREEN))
// 	{
// 		var->r_dy -= 10;
// 		if (ft_check_surround(var, GREEN))
// 			var->vertical = true;
// 	}
// 	var->r_dx = temp_1;
// 	var->r_dy = temp_2;
// 	ft_colour_picker(var);
// }
