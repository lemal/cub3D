/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:26:54 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/31 14:41:39 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <mlx.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define BLACK 0x000000
# define PLAYER 0xFF00F0
# define RED 0xFF0000
# define YELLOW 0xFFFF00
# define WHITE 0xFCFCFF
# define ORANGE 0xFFA500
# define WIDTH 900
# define HEIGHT 600
# define PI 3.14159236535
#include <stdio.h>
typedef struct s_struct
{
	char	*map;
	void	*mlx_draw;
	void	*mlx_obj;
	void	*mlx_window;
	void	*mlx_image;
	void	*mlx_addr;
	int		bpp;
	int		line_size;
	int		endian;
	int		color;
	int		addr_x;
	int		addr_y;
	int		len_rect_x;
	int		p_x;
	int		p_y;
	float	p_look_angle;
	float	r_angle;
	float	r_dx;
	float	r_dy;
	bool	top_left;
	bool	top_right;
	bool	bot_left;
	bool	bot_right;
	//second mlx_objects
	void	*mlx_env;
	void	*mlx_env_window;
	void	*mlx_env_img;
	void	*mlx_env_addr;
	int		env_bpp;
	int		env_line_size;
	int		env_endian;
	int		env_addr_x;
	int		env_addr_y;
	int		env_color;
	int		env_len_rect_x;
	//xpm_colours
	int		c_north;
	int		c_south;
	int		c_east;
	int		c_west;
} t_type;
char	*ft_mlx_setup(t_type *var);
void	ft_game(t_type	*var);
void	ft_draw_back(t_type *var);
void	ft_draw_rect(t_type *var, int x, int y, int	size);
void	ft_player_setup(t_type *var);
void	ft_mv_control(int keysym, t_type *var);
void	ft_draw_minimap(t_type *var);
void	ft_fill_pixel(t_type *var);
void	ft_fill_env_pixel(t_type *var);
void	ft_trace_distance(t_type *var);
bool	ft_check_surround(t_type *var, int color);
void	ft_wall_select(t_type *var, float x, float y);
bool	ft_compare_color(t_type *var, int color);
bool	ft_decr_y(t_type *var, float y);
bool	ft_incr_y(t_type *var, float y);
bool	ft_decr_x(t_type *var, float x);
bool	ft_incr_x(t_type *var, float x);
bool	ft_ye_wall_colour(t_type *var);
#endif
