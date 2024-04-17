/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:48:29 by liaydiny          #+#    #+#             */
/*   Updated: 2023/02/07 20:24:05 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*char *ft_strnstr(const char *haystack,const char *needle,size_t len)
{
	size_t i = 0;
	size_t n_len  = strlen(needle);
	printf(" len is %zu\n",n_len);
	if (n_len == len )
		return ((char *)haystack);
	while (len > n_len)
	{	
		len--;
		if(memcmp(haystack,needle,n_len) == 0)
		{
			return (char *)haystack;
		}
		haystack++;
	}
	return (char *)(needle);
}
int main ()
{
	char *hay;
	hay = malloc(sizeof(char) * 25);
	hay = "garunamarashundzmer\0";
	char *n = "amar";
	int k = 6;	printf("%s\n",ft_strnstr(hay,n,k));
	printf("%s\n",ft_strnstr("garunamarashun-inch ka","shun",3));
}
*/

char	*ft_strnstr(const char *hay, const char *ned, size_t len)
{
	size_t	l;
	size_t	i;
	size_t	j;

	j = 0;
	l = ft_strlen(ned);
	if (!*ned)
		return ((char *)hay);
	while (hay[j] && j < len)
	{
		i = 0;
		if (hay[j] == ned[i])
		{
			while (hay[j + i] && ned[i]
				&& hay[i + j] == ned[i] && (i + j < len))
				i++;
			if (i == l)
				return ((char *)&hay[j]);
		}
		j++;
	}
	return (0);
}
