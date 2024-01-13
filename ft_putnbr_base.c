/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 18:50:47 by alaassir          #+#    #+#             */
/*   Updated: 2023/11/25 13:08:01 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	nlen(long ptr, int base)
{
	int	i;

	i = 0;
	if (ptr == 0)
		return (1);
	else if (ptr < 0)
	{
		ptr *= -1;
		i++;
	}
	while (ptr > 0 && ptr / 10 >= 0)
	{
		ptr /= base;
		i++;
	}
	return (i);
}

static int	do_putnbr_base(long nbr, char *base, int i)
{
	long	len;

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
		do_putnbr_base(nbr / len, base, i);
		do_putnbr_base(nbr % len, base, i);
	}
	return (i);
}

int	ft_putnbr_base(long nbr, char *base)
{
	int	i;

	i = 0;
	i += do_putnbr_base(nbr, base, i);
	return (nlen(nbr, ft_strlen(base)));
}
