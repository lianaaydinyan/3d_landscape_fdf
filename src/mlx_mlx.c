/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_mlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:20:56 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/25 15:20:57 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_mapolo *map)
{
	mlx_destroy_window(map->mlx, map->win);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = NULL;
	if ((x > 0 && y > 0) && (x < W && y < H))
	{
		dst = data->addr + (y * data->line_length
				+ x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
	}
}

void	closing(t_mapolo	*map)
{
	mlx_hook(map->win, 17, 0, close_window, map);
}

void	key_codes_2(int key, t_mapolo *map)
{
	if (key == 69 || key == 24)
		map->zoom += 14;
	else if ((key == 78 || key == 27) && map->zoom > 0)
		map->zoom -= 4;
	else if (key == 126)
		map->downing -= 20;
	else if (key == 124)
		map->centering -= 20;
	else if (key == 125)
		map->downing += 20;
	else if (key == 123)
		map->centering += 20;
	else if (key == 43)
		map->alfa += 0.1;
	else if (key == 47)
		map->alfa -= 0.07;
}

int	key_codes_1(int key, t_mapolo *map, t_data img)
{
	int	i;

	i = -1;
	if (key == 53)
	{
		mlx_destroy_window(map->mlx, map->win);
		exit(0);
	}
	key_codes_2(key, map);
	mlx_clear_window(map->mlx, map->win);
	img.img = mlx_new_image(map->mlx, W, H);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
			&img.endian);
	draw_map2d(map, img);
	mlx_put_image_to_window(map->mlx, map->win, img.img, 0, 0);
	return (0);
}
