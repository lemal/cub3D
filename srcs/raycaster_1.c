/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/13 16:07:41 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"



// void	ft_one_ray(t_type *var)
// {
// 	float	a_tan;
// 	var->r_angle = var->p_look_angle;
// 	var->dof = 0;
// 	//check for intersections with lines.
// 	a_tan = -1/tan(var->r_angle);
// 	if (var->r_angle > PI)
// 	{
// 		var->r_y = (((int)var->p_y >> 6) << 6) - 0.0001;
// 		var->r_x = (var->p_y - var->r_y) * a_tan + var->p_x;
// 		var->r_dy = 64;
// 		var->r_dx = -var->r_dy * a_tan;
// 	}
// 	else if (var->r_angle < PI)
// 	{
// 		var->r_y = (((int)var->p_y >> 6) << 6) + 64;
// 		var->r_x = (var->p_y - var->r_y) * a_tan + var->p_x;
// 		var->r_dy = -64;
// 		var->r_dx = -var->r_dy * a_tan;
// 	}
// 	if (!var->r_angle || var->r_angle == PI)
// 	{
// 		var->r_x = var->p_x;
// 		var->r_y = var->p_y;
// 		var->dof = 8;
// 	}
// 	while (var->dof < 8)
// 	{
// 		var->mapx = (int)(var->r_x) >> 6;
// 		var->mapy = (int)(var->r_y) >> 6;
// 		var->mapp = var->mapy * 
// 	}
// }