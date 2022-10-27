/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 14:52:03 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/27 20:01:41 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_render(t_type *var)
{
	
	ft_draw_back(var);
	ft_draw_minimap(var);
	var->color = PLAYER;
	var->len_rect_x = 2;
	ft_draw_rect(var, var->p_x, var->p_y, 4);
	ft_trace_distance(var);
	// mlx_put_image_to_window(var->mlx_obj,
	// 	var->mlx_window, var->mlx_image, 0, 0);
	mlx_put_image_to_window(var->mlx_env,
		var->mlx_env_window, var->mlx_env_img, 0, 0);
	return (0);
}

char	*ft_mlx_setup(t_type *var)
{
	var->mlx_obj = mlx_init();
	var->mlx_env = mlx_init();//!!
	var->p_x = 0;//this places the player somewhere in the map.
	var->p_y = 0;
	var->p_look_angle = 0; //looks north, init offset based on the map.s
	if (!var->mlx_obj)
	{
		write(1, "Error\nMLX error\n", 17);
		return (NULL);
	}
	// var->mlx_window = mlx_new_window(var->mlx_obj, WIDTH, HEIGHT, "cub3d_map");
	var->mlx_env_window = mlx_new_window(var->mlx_env, WIDTH, HEIGHT, "cub3d_walls");//!!
	if (!var->mlx_env_window)
	{
		write(1, "Error\nMLX error\n", 17);
		free(var->mlx_obj);
		return (NULL);
	}
	var->mlx_image = mlx_new_image(var->mlx_obj, WIDTH, HEIGHT);
	var->mlx_env_img = mlx_new_image(var->mlx_env, WIDTH, HEIGHT);//!
	var->mlx_addr = mlx_get_data_addr(var->mlx_image, &var->bpp,
			&var->line_size, &var->endian);
	var->mlx_env_addr = mlx_get_data_addr(var->mlx_env_img, &var->env_bpp,
			&var->env_line_size, &var->env_endian);//!! might need separation.
	return ("HI");
}

int	ft_end(t_type *vars)
{
	mlx_destroy_window(vars->mlx_env, vars->mlx_env_window);
	mlx_destroy_image(vars->mlx_obj, vars->mlx_image);
	mlx_destroy_image(vars->mlx_env, vars->mlx_env_img);
	mlx_destroy_display(vars->mlx_obj);
	free(vars->mlx_env);
	free(vars->mlx_obj);
	write(1, "Bye\n", 5);
	exit(0);
	return (0);
}

int	ft_input(int keysym, t_type *vars)
{
	if (keysym == XK_w || keysym == XK_a ||
		keysym == XK_d || keysym == XK_s ||
		keysym == XK_Left || keysym == XK_Right)
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
	//call the drawer once here to start the game, from movements later.
	mlx_loop_hook(var->mlx_env, &ft_render, var);
	mlx_hook(var->mlx_env_window, KeyPress, KeyPressMask, &ft_input, var);
	mlx_hook(var->mlx_env_window, DestroyNotify,
		StructureNotifyMask, &ft_end, var);
	mlx_loop(var->mlx_env);
	// mlx_loop_hook(var->mlx_obj, &ft_render, var);
	// mlx_hook(var->mlx_window, KeyPress, KeyPressMask, &ft_input, var);
	// mlx_hook(var->mlx_window, DestroyNotify,
	// 	StructureNotifyMask, &ft_end, var);
	// mlx_loop(var->mlx_obj);
}
