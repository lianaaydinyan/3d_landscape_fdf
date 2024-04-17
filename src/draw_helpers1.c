/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:06:27 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/24 21:06:29 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	malenaa(float x, float y)
{
	if (x > y)
		return (x);
	return (y);
}

void	draw_map_helper1(int i, int j, t_point *ket1, t_point *ket2)
{
	ket1->x = j;
	ket1->y = i;
	ket2->x = j + 1;
	ket2->y = i;
}

void	draw_map_helper2(int i, int j, t_point *ket1, t_point *ket2)
{
	ket1->x = j;
	ket1->y = i;
	ket2->x = j;
	ket2->y = i + 1;
}

void	twod_to_treed(t_point *ket1, t_point *ket2, t_mapolo *map)
{
	ket1->x = (ket1->x - ket1->y) * cos(map->alfa);
	ket1->y = (ket1->x + ket1->y) * sin(map->alfa) - ket1->z;
	ket2->x = (ket2->x - ket2->y) * cos(map->alfa);
	ket2->y = (ket2->x + ket2->y) * sin(map->alfa) - ket2->z;
}

void	draw_line(t_mapolo *map, t_data img, t_point ket1, t_point ket2)
{
	float		delta_x;
	float		delta_y;
	float		max_detlas;

	define_heigth(map, &ket1, &ket2);
	zooming(&ket1, &ket2, map);
	twod_to_treed(&ket1, &ket2, map);
	define_colors(&ket1, &ket2);
	pass_win_limit(&ket1, &ket2, map);
	delta_x = ket2.x - ket1.x;
	delta_y = ket2.y - ket1.y;
	max_detlas = malenaa(fabsf(delta_x), fabsf(delta_y));
	delta_x /= max_detlas;
	delta_y /= max_detlas;
	while ((int)(ket2.x - ket1.x) || (int)(ket2.y - ket1.y))
	{
		my_mlx_pixel_put(&img, ket1.x, ket1.y, ket1.color);
		ket1.x += delta_x;
		ket1.y += delta_y;
	}
}
