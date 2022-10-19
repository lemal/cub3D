/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/19 12:47:27 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	ft_first_wall_hit(t_type *var)
{
	float	multiplier;
	int	x;
	int	y;

	multiplier = 6;
	var->r_dx = cos(var->r_angle) * multiplier;
	var->r_dy = sin(var->r_angle) * multiplier;
	while (!ft_compare_color(var, (int)(var->p_x + var->r_dx),
			(int)(var->p_y + var->r_dy), GREEN)) //take care of the vertical and horizontal on the line cases - infinite while. Some kind of boundaries?
	{
		var->r_dx = cos(var->r_angle) * multiplier;
		var->r_dy = sin(var->r_angle) * multiplier;
		multiplier += 0.01;
	}
	//here we have coordinates of the wall cross and computable distance from floats.
	return (powf((powf(var->r_dx, 2) + powf(var->r_dy, 2)), 0.5));//for that angle also execute
}

//final wall drawing - ?

int	ft_trace_distance(t_type *var)
{
	float	r_dist_to_wall;
	float	r_part_size;

	r_part_size = PI / (3 * WIDTH);//one part of the angle
	var->r_angle = var->p_look_angle + (PI / 6);//in the direction the player looks - add fov
	while (var->p_look_angle < var->r_angle)
	{
		var->r_angle -= r_part_size;
		r_dist_to_wall = ft_first_wall_hit(var);//here do stuff
		//the stuff - r_angle minus p_look_angle for this while, p_look angle minus r_angle for second
	}
	while (var->r_angle > var->p_look_angle - (PI / 6))
	{
		var->r_angle -= r_part_size;
		r_dist_to_wall = ft_first_wall_hit(var);
	}
}



//development paused cuz I couldn't motivate this over ^^
// int	ft_quadrant_preset(t_type *var)
// {
// 	if (var->p_look_angle > 0 && var->p_look_angle < PI / 2)
// 		return (0);
// 	if (var->p_look_angle >= PI / 2 && var->p_look_angle < PI)
// 		return (1);
// 	if (var->p_look_angle >= PI && var->p_look_angle < (3 * PI) / 2)
// 		return (2);
// 	if (var->p_look_angle >= (3 * PI) / 2 && var->p_look_angle <= 2 * PI)
// 		return (3);	
// }

// void	ft_quad_one(t_type *var)
// {
// 	bool	horizontal;

// 	horizontal = false;
// 	if (var->p_look_angle > (PI / 4))
// 		horizontal = true;
	
// }

// void	ft_quadrants(t_type *var)
// {
// 	//call a function pointer from the array of function pointers.
// 	void	(*quadrant[4])(t_type *);
// 	int	num;

// 	quadrant[0] = ft_quad_one;
// // quadrant[1] = ft_quad_two;
// // quadrant[2] = ft_quad_three;
// // quadrant[3] = ft_quad_four;
// 	num = ft_quadrant_preset(var);
// 	quadrant[num](var);
// }
