/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:43:18 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/22 13:06:03 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_w_press(t_type *var)
{
	float	temp1;
	float	temp2;
	
	temp1 = var->r_dx;
	temp2 = var->r_dy;
	var->r_dx = 0;
	var->r_dy = -5;
	// var->p_y -= 5;
	if (!ft_compare_color(var, GREEN))
		var->p_y -= 5;
	var->r_dx = temp1;
	var->r_dy = temp2;
}

void	ft_a_press(t_type *var)
{
	float	temp1;
	float	temp2;
	
	temp1 = var->r_dx;
	temp2 = var->r_dy;
	var->r_dx = -5;
	var->r_dy = 0;
	// var->p_x -= 5;
	if (!ft_compare_color(var, GREEN))
		var->p_x -= 5;
	var->r_dx = temp1;
	var->r_dy = temp2;
}

void	ft_d_press(t_type *var)
{
	float	temp1;
	float	temp2;
	
	temp1 = var->r_dx;
	temp2 = var->r_dy;
	var->r_dx = 5;
	var->r_dy = 0;
	// var->p_x += 5;
	if (!ft_compare_color(var, GREEN))
		var->p_x += 5;
	var->r_dx = temp1;
	var->r_dy = temp2;
}

void	ft_s_press(t_type *var)
{
	float	temp1;
	float	temp2;
	
	temp1 = var->r_dx;
	temp2 = var->r_dy;
	var->r_dx = 0;
	var->r_dy = 5;
	// var->p_y += 5;
	if (!ft_compare_color(var, GREEN))
		var->p_y += 5;
	var->r_dx = temp1;
	var->r_dy = temp2;
}

void	ft_mv_control(int keysym, t_type *var)
{
	if (var->p_look_angle < 0)
		var->p_look_angle = 2 * PI;
	else if (var->p_look_angle > 2 * PI)
		var->p_look_angle = 0;
	if (keysym == XK_w)
		ft_w_press(var);
	else if (keysym == XK_a)
		ft_a_press(var);
	else if (keysym == XK_d) //map_size needed for this fix, otherwise drawn nonenv will seg
		ft_d_press(var);
	else if (keysym == XK_s) //control switching should occur for orientation
		ft_s_press(var);
	if (keysym == XK_Left)
		var->p_look_angle -= 0.1;
	else if (keysym == XK_Right)
		var->p_look_angle += 0.1;
	var->p_dx = cos(var->p_look_angle) * 10;
	var->p_dy = sin(var->p_look_angle) * 10;
	// printf("var->p_y is %d\n", var->p_y);
}


//working rend_move
// void	ft_mv_control(int keysym, t_type *var)
// {
// 	if (var->p_look_angle < 0)
// 		var->p_look_angle = 2 * PI;
// 	else if (var->p_look_angle > 2 * PI)
// 		var->p_look_angle = 0;
// 	if (keysym == XK_w )
// 		var->p_y -= 5;//
// 	else if (keysym == XK_a )
// 		var->p_x -= 5;
// 	else if (keysym == XK_d) //map_size needed for this fix, otherwise drawn nonenv will seg
// 		var->p_x += 5;
// 	else if (keysym == XK_s ) //control switching should occur for orientation
// 		var->p_y += 5;
// 	else if (keysym == XK_Left)
// 		var->p_look_angle -= 0.1;
// 	else if (keysym == XK_Right)
// 		var->p_look_angle += 0.1;
// 	var->p_dx = cos(var->p_look_angle) * 10;
// 	var->p_dy = sin(var->p_look_angle) * 10;
// 	printf("var->p_y is %d\n", var->p_y);
// }