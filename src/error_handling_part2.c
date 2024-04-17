/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling_part2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 19:57:43 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/17 19:57:44 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_error(void)
{
	ft_printf("giving none numeric arguments");
	exit(1);
}

void	no_digit(void)
{
	ft_printf("none numeric arguments");
	exit(1);
}

void	width_error(int i)
{
	ft_printf("Error: Width - ");
	ft_printf("[ %d ]", i);
	ft_printf(" exceeds the standard width.");
	exit(1);
}

void	empty_map(void)
{
	ft_printf("your map is empty");
	exit(1);
}

void	split_error(void)
{
	ft_printf("spliting error");
	exit(1);
}
