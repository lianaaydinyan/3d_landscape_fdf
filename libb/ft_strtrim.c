/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 12:04:58 by liaydiny          #+#    #+#             */
/*   Updated: 2023/02/13 18:12:30 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, char const *str)
{
	size_t	i;
	size_t	j;
	char	*new;

	i = 0;
	j = ft_strlen(s1);
	if (!str || !s1)
		return (NULL);
	while (ft_strchr(str, s1[i]) && s1[i])
		i++;
	while (ft_strchr(str, s1[j - 1]) && j > i)
		j--;
	new = ft_substr(s1, i, j - i);
	return (new);
}
