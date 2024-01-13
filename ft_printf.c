/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 00:33:42 by alaassir          #+#    #+#             */
/*   Updated: 2023/11/26 19:37:14 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	surf(const char *str, int *i)
{
	int	cnt;

	cnt = 0;
	while (str[*i] && str[*i] != '%')
		cnt += ft_putchar(str[(*i)++]);
	return (cnt);
}

static int	is_format(char c)
{
	int	i;

	i = 0;
	if (c == '%')
		return (0);
	while (i < 9)
	{
		if ("cspdiuxX"[i] == c)
			return (0);
		i++;
	}
	return (1);
}

static int	do_format(char spc, va_list mv)
{
	int	cnt;

	cnt = 0;
	if (spc == 'c')
		cnt += ft_putchar(va_arg(mv, int));
	else if (spc == 'd' || spc == 'i')
		cnt += ft_putnbr_base(va_arg(mv, int), "0123456789");
	else if (spc == 's')
		cnt += ft_putstr(va_arg(mv, char *));
	else if (spc == 'x')
		cnt += ft_putnbr_base(va_arg(mv, unsigned int), "0123456789abcdef");
	else if (spc == 'X')
		cnt += ft_putnbr_base(va_arg(mv, unsigned int), "0123456789ABCDEF");
	else if (spc == 'u')
		cnt += ft_putnbr_base(va_arg(mv, unsigned int), "0123456789");
	else if (spc == 'p')
		cnt += print_ptr(va_arg(mv, void *));
	else if (spc == '%')
		cnt += ft_putchar('%');
	return (cnt);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		cnt;
	va_list	mv;

	i = 0;
	cnt = 0;
	if (write(1, "", 0) < 0)
		return (-1);
	va_start(mv, str);
	while (str[i])
	{
		cnt += surf(str, &i);
		if (!str[i] || (str[i] == '%' && !str[i + 1]))
			return (cnt);
		else if (str[i] == '%')
			cnt += do_format(str[i + 1], mv);
		if (is_format(str[i + 1]) == 0)
			i += 2;
		else
			i++;
	}
	va_end(mv);
	return (cnt);
}
