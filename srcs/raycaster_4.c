/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 12:48:32 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/27 12:29:34 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
// if (ft_smallest(steps) == 0)
		// ft_wall_select(var, 0);

void	ft_unset_vertical(t_type *var)
{
	var->top = false;
	var->bot = false;
}

void	ft_unset_horizontal(t_type *var)
{
	var->left = false;
	var->right = false;
}

void	ft_colour_set(t_type *var)
{
	if (var->top)
		var->env_color = YELLOW;
	else if (var->bot)
		var->env_color = BLACK;
	else if (var->left)
		var->env_color = ORANGE;
	else if (var->right)
		var->env_color = WHITE;
}

void	ft_wall_select(t_type *var)//called when colour selected
{
	char	*specifier;

	ft_set_wall_faces(var);
	specifier = ft_stepper(var);
	if (*specifier == 'h')
		ft_unset_vertical(var);
	else if (*specifier == 'v')
		ft_unset_horizontal(var);
	ft_colour_set(var);
}

//why is the thing with the angles needed if it is not used?
int	ft_smallest(int	*arr)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (i <= 2)
	{
		if (arr[i] > arr[i + 1])
			j = i + 1;
		i++;
	}
	return (j);
}
