/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:41:38 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/30 16:01:34 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	ft_kij_init(int *k, int *i, int *j)
{
	*k = 0;
	*i = 0;
	*j = 0;
}

void	ft_draw_minimap(t_type *var)
{
	int	i;
	int	j;
	int	k;

	ft_kij_init(&k, &i, &j);
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
}

void	ft_player_setup(t_type *var)
{
	int	k;

	k = 0;
	while (var->map[k])
	{
		if (var->map[k] == 'N' || var->map[k] == 'S'
			|| var->map[k] == 'E' || var->map[k] == 'W')
			break ;
		if (var->map[k] != '\n')
			var->p_x += 40;
		else
		{
			var->p_y += 40;
			var->p_x = 0;
		}
		k++;
	}
}
