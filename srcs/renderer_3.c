/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:41:38 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/22 13:11:31 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//find the players location in .cub file and place him somewhere there

// void	ft_minimap_edges(t_type *var)
// {

// 	int	i;
// 	int	j;
// 	int	k;
// 	int	cube_size;

// 	k = 0;//index
// 	i = 0;//pixel offset
// 	j = 0;//pixel offset
// 	while (var->map[k])
// 	{
// 		var->len_rect_x = 40;
// 		cube_size = 1600;
// 		if (var->map[k] == '1')
// 		{
// 			var->len_rect_x = 41;
// 			cube_size = 1681;
// 			var->color = GREEN;
// 		}
// 		else 
// 			var->color = BLUE;
// 		if (var->map[k] != '\n')
// 		{
// 			ft_draw_rect(var, 0 + i, 0 + j, cube_size);
// 			i += 41;
// 		}
// 		else
// 		{
// 			j += 41;
// 			i = 0;		 
// 		}
// 		k++;
// 	}
// }


void	ft_draw_minimap(t_type *var)
{
	int	i;
	int	j;
	int	k;

	k = 0;//index
	i = 0;//pixel offset
	j = 0;//pixel offset
	
	while (var->map[k])
	{
		var->len_rect_x = 40;
		if (var->map[k] == '1')
			var->color = GREEN;
		else 
			var->color = BLUE;
		if (var->map[k] != '\n')
		{
			ft_draw_rect(var, 0 + i, 0 + j, 1600);
			i += 40;
		}
		else
		{
			j += 40;
			i = 0;		 
		}
		k++;
	}
	// ft_minimap_edges(var);
}

void	ft_draw_dir(t_type *var, int x, int y)
{
	int		addr_x;
	int		addr_y;

	addr_x = var->addr_x;
	addr_y = var->addr_y;
	var->color = RED;
	var->addr_x = x + 5 + var->p_dx;
	var->addr_y = y + 5 + var->p_dy;
	ft_fill_pixel(var);
	var->addr_y = addr_y;
	var->addr_x = addr_x;
}

void	ft_player_setup(t_type *var)
{
	// int			i;
	// int			j;
	int			k;

	// i = 0;
	// j = 0;
	// var->p_x = 0;
	// var->p_y = 0;
	k = 0;
	while (var->map[k])
	{
		if (var->map[k] == 'N' || var->map[k] == 'S'
			|| var->map[k] == 'E' || var->map[k] == 'W')
			break;
		if (var->map[k] != '\n')
			var->p_x += 40;
		else
		{
			var->p_y += 40;
			var->p_x = 0;		 
		}
		k++;
	}
	// var->color = PLAYER;
	// var->len_rect_x = 2;
	// ft_draw_rect(var, var->p_x, var->p_y, 4);
	// ft_draw_dir(var, var->p_x + i, var->p_y + j);
}

// void	ft_walls(t_type *var)
// {
// 	//scaled lines, scale HEIGHT
// }