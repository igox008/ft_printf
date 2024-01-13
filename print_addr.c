/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_addr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 05:25:25 by alaassir          #+#    #+#             */
/*   Updated: 2023/11/27 01:24:48 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nlen(size_t ptr)
{
	int	i;

	i = 0;
	if (ptr == 0)
		return (1);
	while (ptr > 0 && ptr / 10 >= 0)
	{
		ptr /= 16;
		i++;
	}
	return (i);
}

static int	ft_putptr(size_t nbr, char *base, int i)
{
	size_t	len;

	len = ft_strlen(base);
	if (nbr < 0)
	{
		i += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr < len)
	{
		i += ft_putchar(base[nbr]);
	}
	if (nbr >= len)
	{
		ft_putptr(nbr / len, base, i);
		ft_putptr(nbr % len, base, i);
	}
	if (i < 0)
		return (0);
	return (nlen(nbr));
}

int	print_ptr(void *ptr)
{
	int	cnt;

	cnt = 0;
	cnt += ft_putstr("0x");
	cnt += ft_putptr((size_t)ptr, "0123456789abcdef", cnt);
	return (cnt);
}
