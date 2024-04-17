/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:42:48 by liaydiny          #+#    #+#             */
/*   Updated: 2023/02/07 20:32:53 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*news;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if ((size_t)start >= ft_strlen(s))
		return (ft_strdup("\0"));
	if (len > ft_strlen(s))
		len = ft_strlen(s);
	news = malloc((len + 1) * sizeof(char));
	if (!news)
		return (NULL);
	while (i < len && s[i + (size_t)start])
	{
		news[i] = s[i + (size_t)start];
		i++;
	}
	news[i] = '\0';
	return (news);
}
