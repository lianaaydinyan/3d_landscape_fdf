/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <liaydiny@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:03:18 by liaydiny          #+#    #+#             */
/*   Updated: 2023/03/01 20:28:48 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

//int ft_addres(unsigned long long n);
int	ft_printf_hex(unsigned int n);
int	ft_printf_hex_up(unsigned int n);
int	check_baby(char ch, va_list ap);
int	ft_printf(const char *ap, ...);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int	ft_putunbr(unsigned int n);
int	ft_p(unsigned long long n);
int	ft_addres(void *n);

#endif
