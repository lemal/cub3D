/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tapulask <tapulask@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 11:41:38 by tapulask          #+#    #+#             */
/*   Updated: 2022/10/12 13:02:44 by tapulask         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_player(t_type *var)
{
	var->color = 0xFF00F0;
	var->len_rect_x = 50;
	ft_draw_rect(var, 450, 300, 300);
}