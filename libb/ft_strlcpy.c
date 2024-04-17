/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:54:40 by liaydiny          #+#    #+#             */
/*   Updated: 2023/02/07 20:15:27 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;

	i = 0;
	if (dstsize > 0)
	{
		while (src[i] != '\0' && i < dstsize - 1)
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int main()
{
	char a[15] = "hello world";
	char b[5] = "aper";

	char c[15] = "hello world";
	char d[5] = "aper";
	strlcpy(a, b, 4);
	ft_strlcpy(c, d, 4);
	printf("strlcpy : %s\nft_strlcpy: %s\n", a, c);
}
*/
