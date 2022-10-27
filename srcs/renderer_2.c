/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:43:18 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/25 13:56:57 by tapulask         ###   ########.fr       */
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

// void	ft_mv_control(int keysym, t_type *var)
// {
// 	if (var->p_look_angle < 0)
// 		var->p_look_angle = 2 * PI;
// 	else if (var->p_look_angle > 2 * PI)
// 		var->p_look_angle = 0;
// 	if (keysym == XK_w && var->p_y - 5 > 0)
// 		var->p_y -= 5;
// 	else if (keysym == XK_a && var->p_x - 5 > 0)
// 		var->p_x -= 5;
// 	else if (keysym == XK_d && var->p_x + 5 <= WIDTH) //map_size needed for this fix, otherwise drawn nonenv will seg
// 		var->p_x += 5;
// 	else if (keysym == XK_s && var->p_y + 5 <= HEIGHT) //control switching should occur for orientation
// 		var->p_y += 5;
// 	else if (keysym == XK_Left)
// 		var->p_look_angle -= 0.1;
// 	else if (keysym == XK_Right)
// 		var->p_look_angle += 0.1;
// 	var->p_dx = cos(var->p_look_angle) * 10;
// 	var->p_dy = sin(var->p_look_angle) * 10;
// 	printf("var->p_y is %d\n, var->p_x is %d\n", var->p_y, var->p_x);
// }