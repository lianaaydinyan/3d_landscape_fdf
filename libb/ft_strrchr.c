/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:30:48 by liaydiny          #+#    #+#             */
/*   Updated: 2023/02/13 19:37:58 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int ch)
{
	int		len;
	char	c;

	c = ch;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (s[len] == c)
			return ((char *)(s + len));
		len--;
	}
	return (NULL);
}
