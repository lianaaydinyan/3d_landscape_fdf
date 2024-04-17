/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 11:05:22 by liaydiny          #+#    #+#             */
/*   Updated: 2023/02/13 18:12:10 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoi(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*news;
	size_t	len;

	i = 0;
	j = 0;
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	news = malloc ((len) * (sizeof(char)));
	if (!news || !s2)
		return (NULL);
	while (s1[i])
	{
		news[i] = (char)s1[i];
		i++;
	}
	while (s2[j])
	{
		news[i + j] = (char)s2[j];
		j++;
	}
	news[i + j] = '\0';
	return (news);
}
