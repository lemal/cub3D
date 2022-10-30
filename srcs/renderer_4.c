/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:41:38 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/30 20:32:35 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//functions that get the truecolor values from textures
//by opening them, reading first elem in and closing the xpm image.

char	*ft_north(t_type *var)
{
	char	*relative_path = "./srcs/colours/north.xpm";
	void	*mlx;
	void	*mlx_img;
	int		pos[5];

	mlx = mlx_init();
	if (!mlx)
	{
		write(1, "Error\nMLX error\n", 17);
		return (NULL);
	}
	mlx_img = mlx_xpm_file_to_image(mlx, relative_path,
			&pos[0], &pos[1]);
	if (!mlx_img)
	{
		write(1, "Error\nMLX error\n", 17);
		return (NULL);
	}
	var->c_north = *(int *)mlx_get_data_addr(mlx_img, &pos[2], &pos[3], &pos[4]);
	mlx_destroy_image(mlx, mlx_img);
	mlx_destroy_display(mlx);
	free(mlx);
	return ("ok");
}


char	*ft_south(t_type *var)
{
	char	*relative_path = "./srcs/colours/south.xpm";
	void	*mlx;
	void	*mlx_img;
	int		pos[5];

	mlx = mlx_init();
	if (!mlx)
	{
		write(1, "Error\nMLX error\n", 17);
		return (NULL);
	}
	mlx_img = mlx_xpm_file_to_image(mlx, relative_path,
			&pos[0], &pos[1]);
	if (!mlx_img)
	{
		write(1, "Error\nMLX error\n", 17);
		return (NULL);
	}
	var->c_south = *(int *)mlx_get_data_addr(mlx_img, &pos[2], &pos[3], &pos[4]);
	mlx_destroy_image(mlx, mlx_img);
	mlx_destroy_display(mlx);
	free(mlx);
	return ("ok");
}

char	*ft_east(t_type *var)
{
	char	*relative_path = "./srcs/colours/east.xpm";
	void	*mlx;
	void	*mlx_img;
	int		pos[5];

	mlx = mlx_init();
	if (!mlx)
	{
		write(1, "Error\nMLX error\n", 17);
		return (NULL);
	}
	mlx_img = mlx_xpm_file_to_image(mlx, relative_path,
			&pos[0], &pos[1]);
	if (!mlx_img)
	{
		write(1, "Error\nMLX error\n", 17);
		return (NULL);
	}
	var->c_east = *(int *)mlx_get_data_addr(mlx_img, &pos[2], &pos[3], &pos[4]);
	mlx_destroy_image(mlx, mlx_img);
	mlx_destroy_display(mlx);
	free(mlx);
	return ("ok");
}

char	*ft_west(t_type *var)
{
	char	*relative_path = "./srcs/colours/west.xpm";
	void	*mlx;
	void	*mlx_img;
	int		pos[5];

	mlx = mlx_init();
	if (!mlx)
	{
		write(1, "Error\nMLX error\n", 17);
		return (NULL);
	}
	mlx_img = mlx_xpm_file_to_image(mlx, relative_path,
			&pos[0], &pos[1]);
	if (!mlx_img)
	{
		write(1, "Error\nMLX error\n", 17);
		return (NULL);
	}
	var->c_west = *(int *)mlx_get_data_addr(mlx_img, &pos[2], &pos[3], &pos[4]);
	mlx_destroy_image(mlx, mlx_img);
	mlx_destroy_display(mlx);
	free(mlx);
	return ("ok");
}

bool	ft_ye_wall_colour(t_type *var)
{
	var->c_east = 0;
	var->c_north = 0;
	var->c_west = 0;
	var->c_south = 0;
	if (ft_west(var) && ft_south(var) && ft_east(var) && ft_north(var))
		return (true);
	return (false);
}