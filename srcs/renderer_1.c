/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:52:03 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/12 17:16:00 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_render(t_type *var)
{
	
	ft_draw_back(var);
	ft_draw_minimap(var);
	ft_player(var);
	mlx_put_image_to_window(var->mlx_obj,
		var->mlx_window, var->mlx_image, 0, 0);
	return (0);
}

char	*ft_mlx_setup(t_type *var)
{
	var->mlx_obj = mlx_init();
	var->p_x = 0;//this places the player somewhere in the map.
	var->p_y = 0;
	if (!var->mlx_obj)
	{
		write(1, "Error\nMLX error\n", 17);
		return (NULL);
	}
	var->mlx_window = mlx_new_window(var->mlx_obj, WIDTH, HEIGHT, "so_long");
	if (!var->mlx_window)
	{
		write(1, "Error\nMLX error\n", 17);
		free(var->mlx_obj);
		return (NULL);
	}
	var->mlx_image = mlx_new_image(var->mlx_obj, WIDTH, HEIGHT);
	var->mlx_addr = mlx_get_data_addr(var->mlx_image, &var->bpp,
			&var->line_size, &var->endian);
	return ("HI");
}

int	ft_end(t_type *vars)
{
	mlx_destroy_window(vars->mlx_obj, vars->mlx_window);
	mlx_destroy_image(vars->mlx_obj, vars->mlx_image);
	mlx_destroy_display(vars->mlx_obj);
	free(vars->mlx_obj);
	write(1, "Bye\n", 5);
	exit(0);
	return (0);
}

int	ft_input(int keysym, t_type *vars)
{
	if (keysym == XK_w || keysym == XK_a || keysym == XK_d || keysym == XK_s)
	{
		ft_mv_control(keysym, vars);
		return (0);
	}
	if (keysym == XK_Escape)
		ft_end(vars);
	return (0);
}

void	ft_game(t_type	*var)
{
	mlx_loop_hook(var->mlx_obj, &ft_render, var);
	mlx_hook(var->mlx_window, KeyPress, KeyPressMask, &ft_input, var);
	mlx_hook(var->mlx_window, DestroyNotify,
		StructureNotifyMask, &ft_end, var);
	mlx_loop(var->mlx_obj);
}