/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:43:18 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/12 11:39:11 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_fill_pixel(t_type *var)
{
	char	*pixel;

	pixel = var->mlx_addr + (var->line_size * var->addr_y
			+ (var->bpp / 8) * var->addr_x);
	*(int *)pixel = var->color;
}

void	ft_draw_rect(t_type *var, int x, int y, int	size)
{
	int	i;
	int	j;
	int	tot;

	tot = 0;
	i = x;
	j = y;
	while (tot < size)
	{
		while (i < WIDTH)
		{
			var->addr_x = i;
			var->addr_y = j;
			ft_fill_pixel(var);
			i++;
			tot++;
		}
		i = 0;
		j++;
	}
}

void	ft_draw_back(t_type *var)
{
	var->color = 0x00FF00;
	ft_draw_rect(var, 0, 0, (WIDTH * HEIGHT) / 2);
	var->color = 0xFF0000;
	ft_draw_rect(var, 0, HEIGHT / 2, (WIDTH * HEIGHT) / 2);
}