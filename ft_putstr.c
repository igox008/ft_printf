/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 07:57:21 by alaassir          #+#    #+#             */
/*   Updated: 2023/11/25 09:33:35 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (s == NULL)
		cnt += ft_putstr("(null)");
	else
	{
		while (s[i])
		{
			cnt += write(1, &s[i], 1);
			i++;
		}
	}
	return (cnt);
}
