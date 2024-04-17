/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <liaydiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:45:08 by liaydiny          #+#    #+#             */
/*   Updated: 2023/03/01 20:24:05 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count = ft_putunbr(n / 10);
	count++;
	ft_putchar("0123456789"[n % 10]);
	return (count);
}

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
	{
		write(1, &(s[i]), 1);
		i++;
	}
	return (i);
}

int	ft_putnbr(int n)
{
	unsigned int	nb;
	int				i;
	int				nsh;

	i = 0;
	nsh = 0;
	if (n < 0)
	{
		nsh = ft_putchar('-');
		nb = (unsigned int)(-n);
	}
	else
		nb = (unsigned int)n;
	if (nb >= 10)
		i = ft_putnbr(nb / 10);
	i++;
	ft_putchar((nb % 10) + 48);
	return (i + nsh);
}

int	ft_p(unsigned long long n)
{
	int	i;

	i = 0;
	if (n > 15)
		i = ft_p(n / 16);
	i++;
	ft_putchar("0123456789abcdef"[n % 16]);
	return (i);
}
