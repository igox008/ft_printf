/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:12:34 by alaassir          #+#    #+#             */
/*   Updated: 2023/11/25 13:03:46 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putnbr_base(long nbr, char *base);
int		ft_putstr(char *s);
size_t	ft_strlen(const char *str);
int		print_ptr(void *ptr);

#endif
