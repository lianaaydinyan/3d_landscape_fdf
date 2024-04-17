/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:38:58 by liaydiny          #+#    #+#             */
/*   Updated: 2023/02/07 20:46:33 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	len(long nb)
{
	int	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*zro(int nb)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * 2);
	if (nb == 0)
	{
		str[i] = '0';
		str[++i] = '\0';
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	char	*str;
	long	n;
	int		l;

	n = nb;
	l = len(nb);
	if (n == 0)
		return (zro(n));
	str = malloc((l + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[l--] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[l] = 48 + (n % 10);
		n = (n / 10);
		l--;
	}
	return (str);
}
