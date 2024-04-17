/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <liaydiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 01:58:59 by liaydiny          #+#    #+#             */
/*   Updated: 2023/03/01 20:26:27 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_hex_up(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 15)
		i = ft_printf_hex_up(n / 16);
	i++;
	ft_putchar("0123456789ABCDEF"[n % 16]);
	return (i);
}

int	ft_printf_hex(unsigned int n)
{
	int	i;

	i = 0;
	if (n > 15)
		i = ft_printf_hex(n / 16);
	i++;
	ft_putchar("0123456789abcdef"[n % 16]);
	return (i);
}

int	ft_addres(void *n)
{
	int					count;
	unsigned long long	p;

	p = (unsigned long long)n;
	count = write(1, "0x", 2);
	count += ft_p(p);
	return (count);
}

int	check_baby(char ch, va_list appo)
{
	int	qanak;

	qanak = 0;
	if (ch == '%')
		qanak = ft_putchar('%');
	else if (ch == 'c')
		qanak = ft_putchar(va_arg(appo, int));
	else if (ch == 's')
		qanak = ft_putstr(va_arg (appo, char *));
	else if (ch == 'u')
		qanak = ft_putunbr(va_arg(appo, unsigned int ));
	else if (ch == 'p')
		qanak = ft_addres(va_arg(appo, void *));
	else if (ch == 'd' || ch == 'i')
		qanak = ft_putnbr(va_arg(appo, int));
	else if (ch == 'x')
		qanak = ft_printf_hex(va_arg(appo, unsigned int));
	else if (ch == 'X')
		qanak = ft_printf_hex_up(va_arg(appo, unsigned int));
	return (qanak);
}

int	ft_printf(const char *api, ...)
{
	va_list	apo;
	int		qanak;
	int		i;

	i = 0;
	qanak = 0;
	va_start(apo, api);
	while (api[i])
	{
		if (api[i] == '%' && api[i + 1])
		{
			i++;
			if (api[i])
				qanak += check_baby(api[i], apo);
		}
		else if (api[i] == '%' && !api[i + 1])
		{
			break ;
		}
		else
			qanak += write(1, &api[i], 1);
		i++;
	}
	va_end(apo);
	return (qanak);
}

// int main ()
// {

// 	char *ptr = "Hello world!";
// 	char *np = 0;
// 	int i = 5;
// 	unsigned int bs = sizeof(int)*8;
// 	int mi;
// //	char buf[80];

// 	mi = (1 << (bs-1)) + 1;
// 	ft_printf("%s\n", ptr);
// 	ft_printf("printf test\n");
// 	ft_printf("%s is null pointer\n", np);
// 	ft_printf("%d = 5\n", i);
// 	ft_printf("%d = - max int\n", mi);
// 	ft_printf("char %c = 'a'\n", 'a');
// 	ft_printf("hex %x = ff\n", 0xff);
// 	ft_printf("hex %02x = 00\n", 0);
// 	ft_printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
// 	ft_printf("%d %s(s)", 0, "message");
// 	ft_printf("\n");
// 	ft_printf("%d %s(s) with %%\n", 0, "message");
// 	printf("--------------------------------------");
// 	printf("%s\n", ptr);
// 	printf("printf test\n");
// 	printf("%s is null pointer\n", np);
// 	printf("%d = 5\n", i);
// 	printf("%d = - max int\n", mi);
// 	printf("char %c = 'a'\n", 'a');
// 	printf("hex %x = ff\n", 0xff);
// 	printf("hex %02x = 00\n", 0);
// 	printf("signed %d = unsigned %u = hex %x\n", -3, -3, -3);
// 	printf("%d %s(s)", 0, "message");	
// }
