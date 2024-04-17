/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 21:06:55 by liaydiny          #+#    #+#             */
/*   Updated: 2023/06/25 14:49:36 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	digit_count(char *line, t_mapolo *map)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (line[i])
	{
		if (is_valid_word_char(line[i]))
		{
			count++;
			while (is_valid_word_char(line[i]) && line[i])
				i++;
		}
		else
			i++;
	}
	map->width = count;
	return (count);
}

int	is_valid_word_char(char c)
{
	return (((c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F'))
		|| ((c >= '0' && c <= '9') || (c == ',' || c == 'x')));
}

int	is_space(char c)
{
	return ((c == ' ') || (c == '\t') || (c == '\n'));
}

int	line_is_empthy(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	line_checkin(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			if (is_valid_word_char(str[i + 1]))
				i++;
		}
		else if (is_valid_word_char(str[i]) || is_space(str[i]))
			i++;
		else
			no_digit();
	}
	return (1);
}
