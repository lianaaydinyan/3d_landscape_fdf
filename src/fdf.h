/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 15:20:31 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/25 15:20:33 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libb/libft.h"
# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>
# include  <math.h>

# define W 1920
# define H 1080

typedef struct s_mapolo		t_mapolo;
typedef struct s_data		t_data;
typedef struct s_point		t_point;

struct s_mapolo
{
	void	*mlx;
	void	*win;
	int		**arr;
	int		heigth;
	int		width;
	float	alfa;
	int		zoom;
	int		centering;
	int		downing;
	int		w;
	int		h;
};

struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct	s_point
{
	float				x;
	float				y;
	int					z;
	long long int		color;
};

void	no_digit(void);
void	width_error(int i);
void	empty_map(void);
void	split_error(void);
void	args_error(void);
void	open_error(void);
void	next_line(void);
void	allocating(void);
void	map_error(void);
void	no_digit(void);
void	empthy_line(void);
void	width_error(int i);
void	empty_map(void);
void	split_error(void);
float	malenaa(float x, float y);
void	draw_map_helper2(int i, int j, t_point *ket1, t_point *ket2);
void	draw_map_helper1(int i, int j, t_point *ket1, t_point *ket2);
void	twod_to_treed(t_point *ket1, t_point *ket2, t_mapolo *map);
void	draw_line(t_mapolo *map, t_data img, t_point ket1, t_point ket2);
void	define_heigth(t_mapolo *map, t_point *ket1, t_point *ket2);
void	define_colors( t_point *ket1, t_point *ket2);
void	draw_map2d(t_mapolo *map, t_data img);
void	pass_win_limit(t_point *ket1, t_point *ket2, t_mapolo *map);
void	zooming(t_point *ket1, t_point *ket2, t_mapolo *map);
int		line_checkin(char *str);
int		is_space(char c);
void	free_map(int *arr[], t_mapolo *map);
int		is_valid_word_char(char c);
int		digit_count(char *line, t_mapolo *map);
int		key_codes_1(int key, t_mapolo *map, t_data img);
int		close_window(t_mapolo *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	closing(t_mapolo	*map);
void	key_codes_2(int key, t_mapolo *map);
void	get_map_width(t_mapolo *map, char **av);
void	get_map_heigth(t_mapolo *map, char **av);
void	char2d(char **str);
void	fill_struct(char *line, int	*arr);
int		line_is_empthy(char *str);
void	allocate_map(t_mapolo *map);
void	checking(char **av, t_mapolo *map);
void	first_check(char **av, t_mapolo *map);
void	partof_checking(int fd, char *line, t_mapolo *map);

#endif
