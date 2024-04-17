/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liaydiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 19:59:58 by liaydiny          #+#    #+#             */
/*   Updated: 2023/02/07 20:03:35 by liaydiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t count)
{
	unsigned char	*ptr;

	ptr = dest;
	while (count--)
	{
		*ptr = (unsigned char)c;
		ptr++;
	}
	return (dest);
}
