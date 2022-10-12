/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:26:54 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/12 10:30:08 by tapulask         ###   ########.fr       */
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
typedef struct s_struct
{
	void	*mlx_obj;
	void	*mlx_window;
	void	*mlx_image;
	void	*mlx_addr;
	int		bpp;
	int		line_size;
	int		endian;
	int		floor;
	int		ceiling;
} t_type;
char	*ft_mlx_setup(t_type *var);
void	ft_game(t_type	*var);
#endif