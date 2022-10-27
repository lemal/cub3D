/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/27 17:33:45 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//final wall drawing - ?

// void	ft_draw_wall(t_type *var, float theta, float wall_d, int x)
// {
// 	int		i;
// 	int		midpoint;
// 	int		wall_h;
// 	float	wall_height;

// 	i = 0;
// 	midpoint = HEIGHT / 2;
// 	wall_height = HEIGHT / (wall_d * cosf(theta));
// 	wall_h = (int)wall_height / 2;
// 	var->env_color = BLUE;
// 	var->env_addr_x = x;
// 	while (i < midpoint)
// 	{
// 		var->env_addr_y = midpoint - i;
// 		ft_fill_env_pixel(var);
// 		i++;
// 	}
// 	while (i > 0)
// 	{
// 		var->env_addr_y = midpoint + i;
// 		ft_fill_env_pixel(var);
// 		i--;
// 	}
// }

bool	ft_check_surround(t_type *var, int color)
{
	char	*pixel;
	int		x;
	int		y;

	x = (int)(var->p_x + var->r_dx);
	y = (int)(var->p_y + var->r_dy);
	x += var->r_dx;
	y += var->r_dy;
	pixel = var->mlx_addr + (var->line_size * y
			+ (var->bpp / 8) * x);
	if (*(int *)pixel == color)
		return (true);
	return (false);
}

bool	ft_compare_color(t_type *var, int color)
{
	char	*pixel;
	int		x;
	int		y;

	x = (int)(var->p_x + var->r_dx);
	y = (int)(var->p_y + var->r_dy);
	pixel = var->mlx_addr + (var->line_size * y
			+ (var->bpp / 8) * x);
	if (*(int *)pixel == color)
		return (true);
	return (false);
}

float	ft_first_wall_hit(t_type *var)
{
	float	multiplier;

	multiplier = 1;
	// printf("%f, %f\n", var->r_dx, var->r_dy);
	while (true)
	{
		var->r_dx = cosf(var->r_angle) * multiplier;
		var->r_dy = sinf(var->r_angle) * multiplier;
		if (ft_compare_color(var, GREEN))
			break ;
		multiplier += 0.01;
	}
	// var->env_color = RED;
	// ft_wall_select(var, var->r_dx, var->r_dy);
	ft_coordinate_checks(var, var->r_dx, var->r_dy);
	//here we have coordinates of the wall cross and computable distance from floats.
	return (powf((powf(var->r_dx, 2) + powf(var->r_dy, 2)), 0.5));//for that angle also execute
}

void	ft_draw_wall(t_type *var, float theta, float wall_d, int x)
{
	int		scaled_column;
	int		padding;
	int		i;
	
// (void) wall_d;(void) theta;
	i = 0;
	scaled_column = (int)(HEIGHT / (wall_d * cosf(theta)));
	padding = (HEIGHT - scaled_column) / 2;
	if (padding < 0)
		padding = 0;
	// var->env_color = RED;
	var->env_addr_x = x;
	// ft_wall_select(var);
	// ft_wall_colour_set(var);
	while (i < scaled_column)
	{
		var->env_addr_y = padding + i;
		ft_fill_env_pixel(var);
		i++;
	}
	// printf("%f\n", var->r_angle);
}

void	ft_trace_distance(t_type *var)
{
	float	r_part_size;
	int		r_part_num;

	r_part_num = 0;
	r_part_size = PI / (3 * WIDTH);//one part of the angle
	var->r_angle = var->p_look_angle + (PI / 6);//in the direction the player looks - add fov
	while (var->r_angle > var->p_look_angle - (PI / 6))
	{
		var->r_angle -= r_part_size;
		if (var->p_look_angle > var->r_angle)
			ft_draw_wall(var, var->p_look_angle - var->r_angle, ft_first_wall_hit(var), r_part_num);
		else
			ft_draw_wall(var, var->r_angle - var->p_look_angle, ft_first_wall_hit(var), r_part_num);
		r_part_num++;
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
