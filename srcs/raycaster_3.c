/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/27 12:28:53 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//with given r_dx and r_dy + player location, step through the possible vals
// and return the side to be coloured.
//may break if goes negative! -check and correct
//find the smallest unit of steps from given position to border
//based on the operation done and the bools' values, determine what face it is
	//-- and ++ in x, return number of steps smallest

int	ft_step_down_vert(t_type *var)
{
	int		i;
	float	save_r_dx;
	float	save_r_dy;

	i = 1;
	save_r_dx = var->r_dx;
	save_r_dy = var->r_dy;
	while (true)
	{
		var->r_dy += i;
		if (ft_check_surround(var, BLUE) || i == 39)
			break ;
		var->r_dx = save_r_dx;
		var->r_dy = save_r_dy;
		i++;
	}
	var->r_dx = save_r_dx;
	var->r_dy = save_r_dy;
	return (i);
}

int	ft_step_up_vert(t_type *var)
{
	int		i;
	float	save_r_dx;
	float	save_r_dy;

	i = 1;
	save_r_dx = var->r_dx;
	save_r_dy = var->r_dy;
	while (true)
	{
		var->r_dy -= i;
		if (var->r_dy <= 0)
		{
			i++;
			break;
		}
		if (ft_check_surround(var, BLUE) || i == 39)
			break ;
		var->r_dx = save_r_dx;
		var->r_dy = save_r_dy;
		i++;
	}
	var->r_dx = save_r_dx;
	var->r_dy = save_r_dy;
	return (i);
}

int	ft_step_left_hor(t_type *var)
{
	int		i;
	float	save_r_dx;
	float	save_r_dy;

	i = 1;
	save_r_dx = var->r_dx;
	save_r_dy = var->r_dy;
	while (true)
	{
		var->r_dx -= i;
		if (var->r_dx <= 0)
		{
			i++;
			break;
		}
		if (ft_check_surround(var, BLUE) || i == 39)
			break ;
		var->r_dx = save_r_dx;
		var->r_dy = save_r_dy;
		i++;
	}
	var->r_dx = save_r_dx;
	var->r_dy = save_r_dy;
	return (i);
}

int	ft_step_right_hor(t_type *var)
{
	int		i;
	float	save_r_dx;
	float	save_r_dy;

	i = 1;
	save_r_dx = var->r_dx;
	save_r_dy = var->r_dy;
	while (true)
	{
		var->r_dx += i;
		if (ft_check_surround(var, BLUE) || i == 39)
			break ;
		var->r_dx = save_r_dx;
		var->r_dy = save_r_dy;
		i++;
	}
	var->r_dx = save_r_dx;
	var->r_dy = save_r_dy;
	return (i);
}
//what if we leave the map area with jumping the r_dx, r_dy? V
//assume handling of ^^
char	*ft_stepper(t_type *var)
{
	// int	horizontal_steps;
	// int	vertical_steps;
	int	steps[4];
	int	step_store;

	steps[0] = ft_step_left_hor(var);//sees left wall part
	steps[1]= ft_step_right_hor(var);
	steps[2] = ft_step_up_vert(var);
	steps[3] = ft_step_down_vert(var);
	step_store = ft_smallest(steps);
	if (step_store == 0 || step_store == 1)
		return ("horizontal wall");
	else if (step_store == 2 || step_store == 3)
		return ("vertical wall");
	return ("wat");
	// horizontal_steps = ft_step_horizontal(var);
	// vertical_steps = ft_step_vertical(var);
	//ifs for cases, should be a bunch.
}

