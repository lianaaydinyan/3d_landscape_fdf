/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:20:44 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/25 15:20:46 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_file_name(char **av)
{
	char	*file;

	file = av[1];
	if (!file)
		return ;
	file = ft_strchr(file, '.');
	if (!file || ft_strncmp(file, ".fdf", 4) != 0)
	{
		ft_printf("\nI'm sorry, but it appears you have");
		ft_printf(" made an error in composing the file name.");
		ft_printf("Please note that file names should");
		ft_printf("end with the appropriate file extension,");
		ft_printf("such as .fdf.\n");
		exit(1);
	}
}

void	initializing_coordinates(t_mapolo *map)
{
	map->centering = W / 2;
	map->downing = H / 2;
	map->zoom = 20;
	map->alfa = 0.4;
	map->mlx = mlx_init();
	map->win = mlx_new_window (map->mlx, W, H, "LOVEEEEEE!");
}

int	main(int ac, char **av)
{
	t_mapolo	*map;
	t_data		img;

	map = malloc(sizeof(t_mapolo));
	if (!map)
		allocating();
	if (ac == 2)
	{
		error_file_name(av);
		first_check(av, map);
		checking(av, map);
		initializing_coordinates(map);
		img.img = mlx_new_image(map->mlx, W, H);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		draw_map2d(map, img);
		mlx_put_image_to_window(map->mlx, map->win, img.img, 0, 0);
		closing(map);
		mlx_hook(map->win, 02, 0, key_codes_1, map);
		mlx_loop(map->mlx);
	}
	args_error();
	return (0);
}
