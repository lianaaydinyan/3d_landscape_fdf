/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:21:45 by liaydiny          #+#    #+#             */
/*   Updated: 2023/02/15 16:04:29 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *s, size_t dsize)
{
	size_t	j;
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(s);
	j = dlen;
	i = 0;
	if (dsize == 0)
		return (slen);
	if (dsize < dlen)
		return (slen + dsize);
	else
	{
		while (s[i] && (dlen + i) < dsize)
			dst[j++] = s[i++];
		if (dlen + i == dsize && dlen < dsize)
			dst[--j] = '\0';
		else
			dst[j] = '\0';
	}
	return (slen + dlen);
}
