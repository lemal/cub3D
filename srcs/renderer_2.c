/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:43:18 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/12 16:56:41 by tapulask         ###   ########.fr       */
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
		while (i <  x + var->len_rect_x)
		{
			var->addr_x = i;
			var->addr_y = j;
			ft_fill_pixel(var);
			i++;
			tot++;
		}
		i = x;
		j++;
	}
}

void	ft_draw_back(t_type *var)
{
	var->color = BLACK;
	var->len_rect_x = WIDTH;
	ft_draw_rect(var, 0, 0, (WIDTH * HEIGHT));
	// var->color = GREEN;
	// ft_draw_rect(var, 0, 0, (WIDTH * HEIGHT) / 2);
	// var->color = BLUE;
	// ft_draw_rect(var, 0, HEIGHT / 2, (WIDTH * HEIGHT) / 2);
}

void	ft_mv_control(int keysym, t_type *var)
{
	if (keysym == XK_w)
		var->p_y -= 5;
	else if (keysym == XK_a)
		var->p_x -= 5;
	else if (keysym == XK_d)
		var->p_x += 5;
	else if (keysym == XK_s)
		var->p_y += 5;
}
