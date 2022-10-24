/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rend_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:43:18 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/24 11:27:11 by tapulask         ###   ########.fr       */
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
	var->r_dy = 2;
	if (!ft_check_surround(var, GREEN))
		var->p_y += 2;
	var->r_dx = temp1;
	var->r_dy = temp2;
}

void	ft_a_press(t_type *var)
{
	float	temp1;
	float	temp2;
	
	temp1 = var->r_dx;
	temp2 = var->r_dy;
	var->r_dx = -2;
	var->r_dy = 0;
	if (!ft_check_surround(var, GREEN))
		var->p_x -= 2;
	var->r_dx = temp1;
	var->r_dy = temp2;
}

void	ft_d_press(t_type *var)
{
	float	temp1;
	float	temp2;
	
	temp1 = var->r_dx;
	temp2 = var->r_dy;
	var->r_dx = 2;
	var->r_dy = 0;
	if (!ft_check_surround(var, GREEN))
		var->p_x += 2;
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
	var->r_dy = -2;
	if (!ft_check_surround(var, GREEN))
		var->p_y -= 2;
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
	else if (keysym == XK_d)
		ft_d_press(var);
	else if (keysym == XK_s)
		ft_s_press(var);
	if (keysym == XK_Left)
		var->p_look_angle += 0.1;
	else if (keysym == XK_Right)
		var->p_look_angle -= 0.1;
	var->p_dx = cos(var->p_look_angle) * 10;
	var->p_dy = sin(var->p_look_angle) * 10;
	// printf("var->p_y is %d\n", var->p_y);
}
