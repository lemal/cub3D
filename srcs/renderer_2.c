/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:43:18 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/27 20:04:22 by tapulask         ###   ########.fr       */
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

void	ft_fill_env_pixel(t_type *var)
{
	char	*pixel;

	pixel = var->mlx_env_addr + (var->env_line_size * var->env_addr_y
			+ (var->env_bpp / 8) * var->env_addr_x);
	*(int *)pixel = var->env_color;
}

void	ft_draw_env_rect(t_type *var, int x, int y, int	size)
{
	int	i;
	int	j;
	int	tot;

	tot = 0;
	i = x;
	j = y;
	while (tot < size)
	{
		while (i <  x + var->env_len_rect_x)
		{
			var->env_addr_x = i;
			var->env_addr_y = j;
			ft_fill_env_pixel(var);
			i++;
			tot++;
		}
		i = x;
		j++;
	}
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
	var->env_color = BLACK;
	var->env_len_rect_x = WIDTH;
	ft_draw_env_rect(var, 0, 0, (WIDTH * HEIGHT));
	var->env_color = GREEN;
	ft_draw_env_rect(var, 0, 0, (WIDTH * HEIGHT) / 2);
	var->env_color = BLUE;
	ft_draw_env_rect(var, 0, HEIGHT / 2, (WIDTH * HEIGHT) / 2);
}
