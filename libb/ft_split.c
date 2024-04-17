/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 10:00:47 by liaydiny          #+#    #+#             */
/*   Updated: 2023/02/15 16:25:11 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	count_words(const char *str, char c)
{
	int	i;
	int	t;

	i = 0;
	t = 0;
	while (*str)
	{
		if (*str != c && t == 0)
		{
			t = 1;
			i++;
		}
		else if (*str == c)
			t = 0;
		str++;
	}
	return (i);
}

char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split || !s)
		return (NULL);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
	}
	split[j] = 0;
	return (split);
}
