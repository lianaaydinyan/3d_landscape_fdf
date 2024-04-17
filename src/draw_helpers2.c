/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_helpers2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:06:36 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/24 21:06:37 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	define_heigth(t_mapolo *map, t_point *ket1, t_point *ket2)
{
	ket1->z = map->arr[(int)ket1->y][(int)ket1->x];
	ket2->z = map->arr[(int)ket2->y][(int)ket2->x];
}

void	define_colors(t_point *ket1, t_point *ket2)
{
	if (ket1->z == 0 || ket2->z == 0)
		ket1->color = 0x0A7CAF2;
	else if ((ket1->z > 0 && ket1->z < 10) && (ket2->z > 0 && ket2->z < 10))
		ket1->color = 0x00056FF;
	else if ((ket1->z >= 10 && ket1->z < 15) && (ket2->z >= 10 && ket2->z < 15))
		ket1->color = 0x8A2BE2;
	else if ((ket1->z >= 15 && ket1->z < 55) && (ket2->z >= 15 && ket2->z < 55))
		ket1->color = 0xB22222;
	else if ((ket1->z >= 55 && ket1->z < 105)
		&& (ket2->z >= 55 && ket2->z < 105))
		ket1->color = 0x9932CC;
	else if ((ket1->z >= 105 && ket1->z < 155)
		&& (ket2->z >= 105 && ket2->z < 155))
		ket1->color = 0x9370DB;
	else if ((ket1->z >= 155 && ket1->z < 205)
		&& (ket2->z >= 155 && ket2->z < 205))
		ket1->color = 0x8B008B;
	else if ((ket1->z >= 205 && ket1->z < 235)
		&& (ket2->z >= 205 && ket2->z < 235))
		ket1->color = 0x800080;
	else if ((ket1->z >= 235 && ket1->z < 240)
		&& (ket2->z >= 235 && ket2->z < 240))
		ket1->color = 0x000FFFF;
	else
		ket1->color = 0x9370DB;
}

void	draw_map2d(t_mapolo *map, t_data img)
{
	int		i;
	int		j;
	t_point	ket1;
	t_point	ket2;

	i = -1;
	while (++i < map->heigth)
	{
		j = -1;
		while (++j < map->width)
		{
			if (j != map->width - 1)
			{
				draw_map_helper1(i, j, &ket1, &ket2);
				draw_line(map, img, ket1, ket2);
			}
			if (i != map->heigth - 1)
			{
				draw_map_helper2(i, j, &ket1, &ket2);
				draw_line(map, img, ket1, ket2);
			}
		}
	}
}

void	pass_win_limit(t_point *ket1, t_point *ket2, t_mapolo *map)
{
	ket1->x += map->centering;
	ket1->y += map->downing;
	ket2->x += map->centering;
	ket2->y += map->downing;
}

void	zooming(t_point *ket1, t_point *ket2, t_mapolo *map)
{
	ket1->x *= map->zoom;
	ket1->y *= map->zoom;
	ket2->x *= map->zoom;
	ket2->y *= map->zoom;
}
