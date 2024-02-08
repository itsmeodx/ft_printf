/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:41:59 by oouaadic          #+#    #+#             */
/*   Updated: 2024/02/02 15:04:36 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse_string(char *str, t_flags *flags)
{
	int		count;
	int		len;

	count = 0;
	if (str == NULL && flags->precision_exist == 1
		&& flags->precision >= 0 && flags->precision < 6)
	{
		count += ft_print_width(flags, 0, 0);
		return (count);
	}
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flags->precision > len)
		flags->precision = len;
	if (flags->precision_exist == 1)
		count += ft_print_str_precision(str, flags);
	else
		count += ft_print_string(str, flags);
	return (count);
}

int	ft_print_string(char *str, t_flags *flags)
{
	int		count;

	count = 0;
	if (flags->minus == 0)
		count += ft_print_width(flags, ft_strlen(str), 0);
	count += ft_putstr(str);
	if (flags->minus == 1)
		count += ft_print_width(flags, ft_strlen(str), 0);
	return (count);
}

int	ft_print_str_precision(char *str, t_flags *flags)
{
	int		count;
	int		i;

	count = 0;
	i = 0;
	if (flags->minus == 0)
		count += ft_print_width(flags, flags->precision, 0);
	while (str[i] && i < flags->precision)
	{
		count += ft_putchar(str[i]);
		i++;
	}
	if (flags->minus == 1)
		count += ft_print_width(flags, flags->precision, 0);
	return (count);
}
