/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/27 19:53:52 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
	// ft_coordinate_checks(var, var->r_dx, var->r_dy);
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
