/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precision.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oouaadic <oouaadic@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:04:18 by oouaadic          #+#    #+#             */
/*   Updated: 2024/01/31 16:05:45 by oouaadic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_parse_precision(const char *format,
							int *i, t_flags *flags)
{
	int		precision;

	precision = 0;
	flags->precision_exist = 1;
	flags->zero = 0;
	(*i)++;
	flags->offset++;
	while (ft_isnumber(format[*i]))
	{
		precision = precision * 10 + (format[*i] - '0');
		flags->offset++;
		(*i)++;
	}
	flags->precision = precision;
	if (!format[*i - 1])
		(*i)--;
}

int	ft_print_precision(t_flags *flags, int len)
{
	int		count;
	int		precision;

	count = 0;
	precision = flags->precision;
	if (flags->sign == 1 && flags->type != 'p')
		count += ft_print_sign(flags);
	while (precision - len > 0)
	{
		count += ft_putchar('0');
		precision--;
	}
	return (count);
}
